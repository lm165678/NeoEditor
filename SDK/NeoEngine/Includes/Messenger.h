//========================================================================
// Copyright (c) 2014 Yannick Pflanzer <neo-engine.de>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================

#include <string>
#include <map>
#include <deque>

#include <MCore.h>

namespace Neo
{

/**
 * @brief The Message struct contains methods and data necessary to transmit
 * an useful message.
 *
 * It stores the sender ID, a message string and a message ID.
 */
struct Message
{
	std::string message;
	unsigned int sender;
	unsigned int messageId;
};

/**
 * @brief The Messenger class is the host of all inboxes for all threads.
 *
 * You can create a new inbox for your thread and request messages from it.
 * This class also handles sending messages to other threads as well.
 */
class Messenger
{
private:
	struct Inbox
	{
		std::string name;
		unsigned int id;

		std::deque<Message> messages;
	};

	std::map<std::string, Inbox> m_boxes;
	MSemaphore* m_semaphore;

	void waitForAccess();
	void finishAccess();

public:
	static Messenger* getInstance() { static Messenger msg; return &msg; }

	/**
	 * @brief Creates a new inbox with the given name for the current thread.
	 * @param name The thread name.
	 * @param id The thread ID.
	 */
	void addInbox(const char* name, unsigned int id);

	/**
	 * @brief Retrieves the current number of messages in the inbox with the given name.
	 * @param name The thread name.
	 * @return The count of unhandled messages.
	 */
	unsigned int getMessagesCount(const char* name);

	/**
	 * @brief Sends a message to a thread.
	 *
	 * Adds the new message to the inbox of the receiving thread.
	 *
	 * @param message A string containing the message.
	 * @param messageId The messageId (can be used to send simple signals)
	 * @param dest The name of the receiver.
	 * @param from The ID of the sender.
	 */
	void sendMessage(const char* message, unsigned int messageId, const char* dest, unsigned int from);

	/**
	 * @brief Returns the next message in the message queue.
	 *
	 * @param threadName The thread name to retrieve the message for.
	 * @return The next message.
	 */
	Message getNextMessage(const char* threadName);
};
}

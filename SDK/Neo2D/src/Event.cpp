#include <Event.h>
#include <Widget.h>
#include <NeoEngine.h>

void Neo2D::Gui::Event::handle()
{
	if(m_callback != nullptr) m_callback(m_receiver, *this, m_data);
	m_receiver.handle(*this);
}
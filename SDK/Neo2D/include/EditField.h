#ifndef NEO_EDITFIELD_H
#define NEO_EDITFIELD_H

#include <Widget.h>
#include "CommonEvents.h"

#include <string>

namespace Neo2D
{
namespace Gui
{

class EditField : public Widget
{
	size_t m_caret;
public:
	EditField(int x,
			  int y,
			  unsigned int w,
			  unsigned int h,
			  const char* label,
			  const shared_ptr<Object2D>& parent,
			  const shared_ptr<Theme>& theme)
		: Widget(x, y, w, h, label, parent, theme),
		  m_caret(0)
	{
		registerEvent(make_shared<MouseOverEvent>(*this, nullptr, nullptr));
		registerEvent(make_shared<MouseLeaveEvent>(*this, nullptr, nullptr));
		registerEvent(make_shared<MouseLeftClickEvent>(*this, nullptr, nullptr));
		registerEvent(make_shared<CharacterInputEvent>(*this, nullptr, nullptr));
		registerEvent(make_shared<KeyPressEvent>(*this, nullptr, nullptr));
	}

	void setCaret(size_t i) { m_caret = i; }
	size_t getCaret() const { return m_caret; }

	virtual void handle(const Event& e) override;
};

}
}
#endif //NEO_EDITFIELD_H
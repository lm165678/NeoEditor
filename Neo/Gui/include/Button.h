/*
 * Copyright 2014 (C) Yannick Pflanzer <neo-engine.de>
 *
 * This file is part of NeoGui.
 *
 * NeoGui is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * NeoGui is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with NeoGui.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Diese Datei ist Teil von NeoGui.
 *
 * NeoGui ist Freie Software: Sie können es unter den Bedingungen
 * der GNU Lesser General Public License, wie von der Free Software Foundation,
 * Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
 * veröffentlichten Version, weiterverbreiten und/oder modifizieren.
 *
 * NeoGui wird in der Hoffnung, dass es nützlich sein wird, aber
 * OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
 * Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
 * Siehe die GNU Lesser General Public License für weitere Details.
 *
 * Sie sollten eine Kopie der GNU Lesser General Public License zusammen mit
 *diesem
 * Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
 */

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <Widget.h>
#include <NeoEngine.h>

namespace Neo
{
namespace Gui
{
/**
 * Represents the state a button can possible have.
 */
enum BUTTON_STATE
{
	/// If the button is neither selected nor pressed
	BUTTON_NORMAL_STATE = 0,
	/// If the button has the mouse cursor over it
	BUTTON_HOVER_STATE,
	/// If the mouse is hovering over the button and the left mouse button is pressed
	BUTTON_PRESSED_STATE 
};

/**
 * @brief Implements a simple pushable button that calls the specified callback.
 *
 * @author Yannick Pflanzer
 */
class NEO2D_EXPORT Button : public Widget
{
protected:
	OText* m_labelText;
	BUTTON_STATE m_state;

public:
	Button(unsigned int x, unsigned int y, unsigned int width,
		   unsigned int height, const char* label);

	void draw();
	void draw(Vector2 offset) { draw(); }
	void update();
};
}
}
#endif

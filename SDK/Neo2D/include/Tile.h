/*
 * Copyright 2014 (C) Yannick Pflanzer <neo-engine.de>
 *
 * This file is part of Neo2D.
 *
 * Neo2D is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Neo2D is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Neo2D.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Diese Datei ist Teil von Neo2D.
 *
 * Neo2D ist Freie Software: Sie können es unter den Bedingungen
 * der GNU Lesser General Public License, wie von der Free Software Foundation,
 * Version 3 der Lizenz oder (nach Ihrer Wahl) jeder späteren
 * veröffentlichten Version, weiterverbreiten und/oder modifizieren.
 *
 * Neo2D wird in der Hoffnung, dass es nützlich sein wird, aber
 * OHNE JEDE GEWÄHRLEISTUNG, bereitgestellt; sogar ohne die implizite
 * Gewährleistung der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
 * Siehe die GNU Lesser General Public License für weitere Details.
 *
 * Sie sollten eine Kopie der GNU Lesser General Public License zusammen mit
 *diesem
 * Programm erhalten haben. Wenn nicht, siehe <http://www.gnu.org/licenses/>.
 */

#ifndef __TILE_H__
#define __TILE_H__

#include <string>
#include <NeoEngine.h>
#include <Widget.h>

namespace Neo2D
{

using namespace Neo;
	
/**
 * @brief Implements a tile sheet from which it is possible to retrieve one
 * specific tile.
 *
 * @author Yannick Pflanzer
 */
class NEO2D_EXPORT TileSheet
{
private:
	int m_image;

	unsigned int m_tileWidth;
	unsigned int m_tileHeight;
	unsigned int m_tileDistance;

	unsigned int m_imageWidth, m_imageHeight;

public:
	TileSheet() : m_image(0) {}

	void loadImage(const char* path, unsigned int width, unsigned int height,
				   unsigned int dist);
	Vector4 getTexCoords(unsigned int x, unsigned int y);
	int getImage() { return m_image; }
};

/**
 * @brief The Tile class displays a texture on the screen.
 *
 * The texture is retrieved using the TileSheet class and can change during
 * runtime.
 *
 * @author Yannick Pflanzer
 */
class NEO2D_EXPORT Tile : public Widget
{
protected:
	OText* m_labelText;
	TileSheet* m_parentSheet;

	unsigned int m_tilex, m_tiley;

public:
	Tile(unsigned int x, unsigned int y, unsigned int width,
		 unsigned int height, const char* label, unsigned int tilex,
		 unsigned int tiley)
		: Widget(x, y, width, height, label),
		  m_labelText(NULL),
		  m_tilex(tilex),
		  m_tiley(tiley)
	{
	}

	const char* getStaticName() { return "Tile"; }

	void setTileSheet(TileSheet* sheet) { m_parentSheet = sheet; }
	void setOffset(Vector2 vec)
	{
		m_tilex = vec.x;
		m_tiley = vec.y;
	}

	void draw(Vector2 offset);
	void update();
};
}
#endif

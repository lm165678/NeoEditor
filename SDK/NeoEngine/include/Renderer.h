//========================================================================
// Copyright (c) 2003-2011 Anael Seghezzi <www.maratis3d.com>
// Copyright (c) 2016 Yannick Pflanzer <www.neo-engine.de>
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


#ifndef __RENDERER_H
#define __RENDERER_H

namespace Neo
{
/**
 * @brief Provides methods to execute higher level graphics operations.
 *
 * Higher level means that it does not operate on OpenGL/etc. API specifics but
 * on Neo::Mesh, Neo::Scene etc. so the caller does not need any knowledge about
 * the underlying framework.
 */
class NEO_ENGINE_EXPORT Renderer
{
public:

	Renderer();
	virtual ~Renderer();

public:

	/**
	 * @brief Destroys the renderer object and frees all resources
	 * occupied by the object.
	 */
	virtual void destroy() = 0;

	/**
	 * @brief Initialized the renderer and all underlying frameworks.
	 */
	virtual void initialize() = 0;

	/**
	 * @brief Retrieves the name of this renderer type.
	 */
	virtual const char* getName() = 0;

	/**
	 * @brief Draws a scene as seen from the perspective of the given camera.
	 *
	 * @param scene The scene to display.
	 * @param camera The camera.
	 */
	virtual void drawScene(Scene* scene, OCamera* camera) = 0;

	/**
	 * @brief Draws a text object in 3D space.
	 *
	 * @param text The text to draw.
	 */
	virtual void drawText(OText* text) = 0;

	/**
	 * @brief Draws an entity on the screen as seen from the perspective of the given camera.
	 *
	 * @param mesh The entity to draw.
	 * @param camera The camera.
	 */
	virtual void drawEntity(OEntity* entity, OCamera* camera) = 0;

	/**
	 * @brief Draws a colored 2D quad to the screen.
	 *
	 * @param position The 2D coordinates of the top left vertex.
	 * @param size The 2D width/height of the quad.
	 * @param color The color to draw with.
	 * @param rotation The angle to rotate around.
	 */
	virtual void drawColoredQuad(const Vector2& position, const Vector2& size, const Vector4& color,
		float rotation) = 0;

	/**
	* @brief Draws a textured 2D quad to the screen.
	*
	* @param position The 2D coordinates of the top left vertex.
	* @param size The 2D width/height of the quad.
	* @param texture The texture to use.
	* @param rotation The angle to rotate around.
	* @param scale The scale of the texture.
	* @param flip A vector indicating mirroring around several axis.
	* @param texcoords The texture coordinates to use.
	*/
	virtual void drawTexturedQuad(const Vector2& position, const Vector2& size, int texture,
		float rotation, const Vector2& scale, const Vector2& flip, const Vector4& texcoords) = 0;

	/**
	* @brief Draws a textured 2D quad to the screen.
	*
	* @param position The 2D coordinates of the top left vertex.
	* @param size The 2D width/height of the quad.
	* @param texture The texture to use.
	* @param rotation The angle to rotate around.
	* @param scale The scale of the texture.
	* @param flip A vector indicating mirroring around several axis.
	*/
	virtual void drawTexturedQuad(const Vector2& position, const Vector2& size, int texture,
		float rotation, const Vector2& scale, const Vector2& flip) = 0;

	/**
	* @brief Draws a textured 2D quad to the screen.
	*
	* @param position The 2D coordinates of the top left vertex.
	* @param size The 2D width/height of the quad.
	* @param texture The texture to use.
	* @param rotation The angle to rotate around.
	* @param scale The scale of the texture.
	*/
	virtual void drawTexturedQuad(const Vector2& position, const Vector2& size, int texture,
		float rotation, const Vector2& scale) = 0;

	/**
	* @brief Draws a textured 2D quad to the screen.
	*
	* @param position The 2D coordinates of the top left vertex.
	* @param size The 2D width/height of the quad.
	* @param texture The texture to use.
	* @param rotation The angle to rotate around.
	*/
	virtual void drawTexturedQuad(const Vector2& position, const Vector2& size, int texture, float rotation) = 0;

	/**
	* @brief Sets a 2D viewport with the given width and height.
	*
	* @param size The 2D vector containing the width and height.
	*/
	virtual void set2D(const Vector2& size) = 0;

	virtual void stopThreads() {}
	virtual void startThreads() {}
	virtual void KillThreads() {}
};
}
#endif
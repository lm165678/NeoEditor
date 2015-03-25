//========================================================================
// Copyright (c) 2003-2011 Anael Seghezzi <www.maratis3d.com>
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

#ifndef __ENGINE_H
#define __ENGINE_H

#ifdef WIN32

	// M_ENGINE_EXPORT
	#if defined(NEO_ENGINE_DLL)
		#define M_ENGINE_EXPORT __declspec( dllexport )
	#elif defined(NEO_ENGINE_STATIC)
		#define M_ENGINE_EXPORT
	#else
		#define M_ENGINE_EXPORT __declspec( dllimport )
	#endif

#else
	// M_ENGINE_EXPORT
	#define M_ENGINE_EXPORT
#endif


// object3d type
#define M_OBJECT3D			0
#define M_OBJECT3D_BONE		1
#define M_OBJECT3D_CAMERA	2
#define M_OBJECT3D_LIGHT	3
#define M_OBJECT3D_ENTITY	4
#define M_OBJECT3D_SOUND	5
#define M_OBJECT3D_TEXT		6

// dataRef type
#define M_REF_MESH				0
#define M_REF_TEXTURE			1
#define M_REF_SOUND				2
#define M_REF_ARMATURE_ANIM		3
#define M_REF_MATERIALS_ANIM	4
#define M_REF_TEXTURES_ANIM		5
#define M_REF_SHADER			6
#define M_REF_FONT				7

// classes
namespace Neo
{
class Scene;
class Level;
class NeoGame;

class Object3d;
class OBone;
class OLight;
class OCamera;
class OEntity;
class OSound;
class OText;

class FontRef;
class ShaderRef;
class SoundRef;
class MeshRef;
class TextureRef;
class ArmatureAnimRef;
class TexturesAnimRef;
class MaterialsAnimRef;
class Messenger;
}

#include <NeoCore.h>

#include "Log.h"

#include "PackageManager.h"

#include "Key.h"
#include "Object3dAnim.h"
#include "TextureAnim.h"
#include "MaterialAnim.h"

#include "ArmatureAnim.h"
#include "TexturesAnim.h"
#include "MaterialsAnim.h"

#include "FXManager.h"
#include "PostProcessor.h"

#include "PointerVariable.h"
#include "Behavior.h"
#include "BehaviorCreator.h"
#include "BehaviorManager.h"

#include "Renderer.h"
#include "RendererCreator.h"
#include "RendererManager.h"

#include "Box3d.h"
#include "Frustum.h"

#include "Font.h"
#include "Texture.h"
#include "Material.h"
#include "Armature.h"
#include "Mesh.h"
#include "MeshTools.h"

#include "FontRef.h"
#include "ShaderRef.h"
#include "SoundRef.h"
#include "MeshRef.h"
#include "TextureRef.h"
#include "ArmatureAnimRef.h"
#include "TexturesAnimRef.h"
#include "MaterialsAnimRef.h"
#include "Skybox.h"

#include "Object3d.h"
#include "OBone.h"
#include "OCamera.h"
#include "OLight.h"
#include "OSound.h"
#include "OEntity.h"
#include "OText.h"

#include "Scene.h"
#include "Level.h"
#include "NeoGame.h"
#include "Messenger.h"

namespace Neo
{
class M_ENGINE_EXPORT NeoEngine
{
public:

	NeoEngine(void);
	~NeoEngine(void);

	// instance
	static NeoEngine * getInstance(void);

private:
	
	// active
	bool m_isActive;
	
	// contexts
	SoundContext * m_soundContext;
	RenderingContext * m_renderingContext;
	PhysicsContext * m_physicsContext;
	ScriptContext * m_scriptContext;
	InputContext * m_inputContext;
	SystemContext * m_systemContext;

	// data loaders
	DataLoader m_fontLoader;
	DataLoader m_imageLoader;
	DataLoader m_soundLoader;
	DataLoader m_meshLoader;
	DataLoader m_armatureAnimLoader;
	DataLoader m_texturesAnimLoader;
	DataLoader m_materialsAnimLoader;
	DataLoader m_levelLoader;

	// behavior manager
	BehaviorManager m_behaviorManager;
	
	// renderer manager
	RendererManager m_rendererManager;

	// package manager
	MPackageManager * m_packageManager;
	
	// level
	Level * m_level;

	// game
	NeoGame * m_game;
	
	// renderer
	Renderer * m_renderer;

	// stores the name of the level to load when loading is save
	char * m_requestedLevelToLoad;
	
private:
	
	void loadLevelIfRequested(); // Checks if a level was requested to be loaded and loads it
	
public:

	// active
	inline void setActive(bool active){ m_isActive = active; }
	inline bool isActive(void){ return m_isActive; }

	// contexts
	void setSoundContext(SoundContext * soundContext);
	void setRenderingContext(RenderingContext * renderingContext);
	void setPhysicsContext(PhysicsContext * physicsContext);
	void setScriptContext(ScriptContext * scriptContext);
	void setInputContext(InputContext * inputContext);
	void setSystemContext(SystemContext * systemContext);

	// get contexts
	inline SoundContext * getSoundContext(void){ return m_soundContext; }
	inline RenderingContext * getRenderingContext(void){ return m_renderingContext; }
	inline PhysicsContext * getPhysicsContext(void){ return m_physicsContext; }
	inline ScriptContext * getScriptContext(void){ return m_scriptContext; }
	inline InputContext * getInputContext(void){ return m_inputContext; }
	inline SystemContext * getSystemContext(void){ return m_systemContext; }

	// data loaders
	DataLoader * getFontLoader(void){ return &m_fontLoader; }
	DataLoader * getImageLoader(void){ return &m_imageLoader; }
	DataLoader * getSoundLoader(void){ return &m_soundLoader; }
	DataLoader * getMeshLoader(void){ return &m_meshLoader; }
	DataLoader * getArmatureAnimLoader(void){ return &m_armatureAnimLoader; }
	DataLoader * getTexturesAnimLoader(void){ return &m_texturesAnimLoader; }
	DataLoader * getMaterialsAnimLoader(void){ return &m_materialsAnimLoader; }
	DataLoader * getLevelLoader(void){ return &m_levelLoader; }

	// behavior manager
	inline BehaviorManager * getBehaviorManager(void){ return &m_behaviorManager; }

	// renderer manager
	inline RendererManager * getRendererManager(void){ return &m_rendererManager; }

	// package manager
	void setPackageManager(MPackageManager * packageManager);
	inline MPackageManager * getPackageManager(void){ return m_packageManager; }

	// update requests
	void updateRequests(void);

	// level
	void setLevel(Level * level);
	bool loadLevel(const char * filename); // loads level immediately
	void requestLoadLevel(const char * filename); // send a request to load a level
	bool doesLevelExist(const char * filename);
	inline Level * getLevel(void){ return m_level; }

	// game
	void setGame(NeoGame * game);
	inline NeoGame * getGame(void){ return m_game; }
	
	// renderer
	void setRenderer(Renderer * renderer);
	inline Renderer * getRenderer(void){ return m_renderer; }
};
}

#endif

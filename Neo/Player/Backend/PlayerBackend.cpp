//========================================================================
//  Maratis, Copyright (c) 2003-2011 Anael Seghezzi <www.maratis3d.com>
//  Neo, Copyright (c) 2014-2015 Yannick Pflanzer <www.neo-engine.de>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software Foundation,
//  Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
//========================================================================

#include "PlayerBackend.h"
#include <Window/Window.h>

#ifndef USE_GLES
#include <GLContext.h>
#else
#include <ES2Context.h>
typedef Neo::ES2Context GLContext;
#endif

#include <ALContext.h>
#include <BulletContext.h>
#include <WinContext.h>
#include <ImageLoader.h>
#include <SoundLoader.h>
#include <FreetypeLoader.h>
#include <BinFontLoader.h>
#include <BinMeshLoader.h>
#include <AssimpMeshLoader.h>

#include <NeoCore.h>
#include <NeoEngine.h>
#include <Window/Mouse.h>
#include <LookAtBehavior.h>
#include <FollowBehavior.h>
#include <LuaBehavior.h>
#include <ParticleSystemBehavior.h>
#include <LuaScript.h>
#include <Input.h>
#include <LevelLoad.h>
#include <LevelSave.h>
#include <MeshLoad.h>
#include <MeshSave.h>
#include <PackageManagerNPK.h>
#include <Project.h>
#include <StandardRenderer.h>
#include <FixedRenderer.h>

using namespace Neo;

PlayerBackend::PlayerBackend(void):
m_gamePlugin(NULL),
m_renderer(NULL)
{
	// MEngine
	{
		m_soundContext = new ALContext();
		m_render = new GLContext();
		m_physics = new BulletContext();
		m_script = new LuaScript();
		m_input = new Input();
		m_system = new MWinContext();
		m_level = new Level();
		m_game = new NeoGame();
		m_packageManager = new PackageManagerNPK();
		
        m_physics->setSimulationQuality(2);

		NeoEngine * engine = NeoEngine::getInstance();

		// package manager
		engine->setPackageManager(m_packageManager);
		m_packageManager->init();

		// contexts
		engine->setSoundContext(m_soundContext); // sound context
		engine->setRenderingContext(m_render); // rendering context
		engine->setPhysicsContext(m_physics); // physics context
		engine->setScriptContext(m_script); // script context
		engine->setInputContext(m_input); // input context
		engine->setSystemContext(m_system); // system context
	}
}

PlayerBackend::~PlayerBackend(void)
{
	clear();

	SAFE_DELETE(m_game);
	SAFE_DELETE(m_level);

	SAFE_DELETE(m_render);
	SAFE_DELETE(m_soundContext);
	SAFE_DELETE(m_physics);
	SAFE_DELETE(m_script);
	SAFE_DELETE(m_input);
	SAFE_DELETE(m_system);
	SAFE_DELETE(m_packageManager);
}

void PlayerBackend::changeRenderer(const char * name)
{
	NeoEngine * engine = NeoEngine::getInstance();
	RendererManager * rendererManager = engine->getRendererManager();
	
	RendererCreator * renderer = rendererManager->getRendererByName(name);
    if(renderer && strcmp(engine->getRenderer()->getName(), name) != 0)
    {
		if(m_renderer)
			m_renderer->destroy();
		m_renderer = renderer->getNewRenderer();
		engine->setRenderer(m_renderer);
	}
}

void PlayerBackend::start(void)
{
	// MEngine
	{
		NeoEngine * engine = NeoEngine::getInstance();

		// loaders
		engine->getImageLoader()->addLoader(M_loadImage); // image loader
		engine->getSoundLoader()->addLoader(M_loadSound); // sound loader
		engine->getLevelLoader()->addLoader(xmlLevelLoad); // level loader
		engine->getFontLoader()->addLoader(M_loadFont); // font loader
		engine->getFontLoader()->addLoader(M_loadBinFont); // bin font loader

		// add behaviors
        engine->getBehaviorManager()->addBehavior(LookAtBehavior::getStaticName(), M_OBJECT3D_CAMERA, LookAtBehavior::getNew);
		engine->getBehaviorManager()->addBehavior(FollowBehavior::getStaticName(), M_OBJECT3D, FollowBehavior::getNew);
        engine->getBehaviorManager()->addBehavior(LuaBehavior::getStaticName(), M_OBJECT3D, LuaBehavior::getNew);
        engine->getBehaviorManager()->addBehavior(ParticleSystemBehavior::getStaticName(), M_OBJECT3D, ParticleSystemBehavior::getNew);

		// add renderers
		engine->getRendererManager()->addRenderer(StandardRenderer::getStaticName(), StandardRenderer::getNew);
		engine->getRendererManager()->addRenderer(FixedRenderer::getStaticName(), FixedRenderer::getNew);
		
		// mesh loader
		engine->getMeshLoader()->addLoader(xmlMeshLoad);
		engine->getMeshLoader()->addLoader(M_loadBinMesh);
		engine->getMeshLoader()->addLoader(M_loadAssimpMesh);
		engine->getArmatureAnimLoader()->addLoader(xmlArmatureAnimLoad);
		engine->getArmatureAnimLoader()->addLoader(M_loadBinArmatureAnim);
		engine->getTexturesAnimLoader()->addLoader(xmlTextureAnimLoad);
		engine->getTexturesAnimLoader()->addLoader(M_loadBinTexturesAnim);
		engine->getMaterialsAnimLoader()->addLoader(xmlMaterialAnimLoad);
        engine->getMaterialsAnimLoader()->addLoader(M_loadBinMaterialsAnim);

		// level
		engine->setLevel(m_level);

		// game
		engine->setGame(m_game);
		
		// set default renderer (standard)
		if(m_renderer == NULL)
			m_renderer = new StandardRenderer();
		engine->setRenderer(m_renderer);
	}
}

void PlayerBackend::clear(void)
{
	NeoEngine * engine = NeoEngine::getInstance();
	
	// level
	m_level->clear();
	if(m_renderer){
		m_renderer->destroy();
		m_renderer = NULL;
	}
	
	// plugins
	SAFE_DELETE(m_gamePlugin);

	unsigned int i;
	unsigned int pSize = m_plugins.size();
	for(i=0; i<pSize; i++)
		SAFE_DELETE(m_plugins[i]);

	m_plugins.clear();

	// MEngine
	{
		// loaders
		engine->getImageLoader()->clear();
		engine->getSoundLoader()->clear();
		engine->getLevelLoader()->clear();
		engine->getFontLoader()->clear();
		engine->getFontLoader()->clear();

		// behaviors
		engine->getBehaviorManager()->clear();
		
		// renderer
		engine->getRendererManager()->clear();

		// mesh loader
		engine->getMeshLoader()->clear();
		engine->getArmatureAnimLoader()->clear();
		engine->getTexturesAnimLoader()->clear();
		engine->getMaterialsAnimLoader()->clear();
	}
}

void PlayerBackend::restart(void)
{
	clear();
	start();
}

void PlayerBackend::loadGamePlugin(void)
{
	char gameFile[256];
	NeoWindow * window = NeoWindow::getInstance();

	#ifdef WIN32
		getGlobalFilename(gameFile, window->getWorkingDirectory(), "Game.dll");
	#elif __APPLE__
		getGlobalFilename(gameFile, window->getWorkingDirectory(), "Game.dylib");
	#elif linux
		getGlobalFilename(gameFile, window->getWorkingDirectory(), "Game.so");
	#endif

	SAFE_DELETE(m_gamePlugin);
	m_gamePlugin = new Plugin();
	m_gamePlugin->load(gameFile);
}

bool PlayerBackend::loadProject(const char * filename)
{
	if(! filename)
		return false;
	
	// load project file
	Project proj;
	if(proj.loadXML(filename))
	{
		loadProject(&proj, filename);
		return true;
	}
	
	return false;
}

void PlayerBackend::loadProject(Project* proj, const char * filename)
{
	NeoWindow * window = NeoWindow::getInstance();
	NeoEngine * engine = NeoEngine::getInstance();
	
	
	// working directory
	char workingDir[256];
	getRepertory(workingDir, filename);
	window->setWorkingDirectory(workingDir);
	
	// restart
	restart();
	loadGamePlugin();
	
	// renderer
	changeRenderer(proj->renderer.c_str());
	
	// if we have a package manager, try to load the package
	if(PackageManager* pPackMan = NeoEngine::getInstance()->getPackageManager())
	{
		char projName[256];
		getLocalFilename(projName, workingDir, filename);
		if(char* ext = strstr(projName, ".mproj"))
		{
			sprintf(ext, ".npk");
			char packageFile[256];
			getGlobalFilename(packageFile, workingDir, projName);
			pPackMan->loadPackage(packageFile);
		}
	}
	
	// load start level
	engine->loadLevel(proj->startLevel.c_str());
}

void PlayerBackend::logicLoop(void)
{
	NeoEngine * engine = NeoEngine::getInstance();

	// game
	NeoGame * game = engine->getGame();
	if(game)
	{
		if(game->isRunning()){
			game->update();
		}
	}
}

void PlayerBackend::graphicLoop(void)
{
	NeoWindow * window = NeoWindow::getInstance();
	NeoEngine * engine = NeoEngine::getInstance();
	RenderingContext * render = engine->getRenderingContext();

	// game
	NeoGame * game = engine->getGame();
	if(game)
	{
		if(game->isRunning())
		{
			render->disableScissorTest();
			render->setViewport(0, 0, window->getWidth(), window->getHeight());
			game->draw();
		}
		else
		{
			render->clear(BUFFER_COLOR);
		}
	}
	else
	{
		render->clear(BUFFER_COLOR);
	}
}

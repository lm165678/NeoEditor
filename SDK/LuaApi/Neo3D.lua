--- The Neo3D Lua API
-- The Neo3D Lua interface delivers an easy to use and object oriented way of
-- accessing the script API.
--
-- Simply include this file ('SDK/Neo3D.lua') into your Lua script to use it.
--
-- This API is not installed by default in your project directory. To install it, use
-- the ProjectManager and click the option '"Copy Lua SDK"' after importing your project.
--
---- Usage
-- Usage of this API is fairly easy. Almost all functionality is about accessing and manipulating
-- Object3d's to create the in-game behavior you want.
--
-- Example:
--[[
  dofile("SDK/Neo3D.lua")

  object = Object3d.getObject("Entity0")

  function onSceneUpdate()
    -- Rotate the object
    object:rotate({0,1,0}, 2)
  end
]]
--
-- The API also contains primitives for accessing the 2D functionality of Neo.
-- To use it simply include 'SDK/Graphics2D.lua' into your game script.
--
-- Example:
--[[
  dofile("SDK/Graphics2D.lua")

  -- Load a sprite
  sprite = Sprite(20,20,90,90,"maps/sprite.png", "")

  -- Add sprite to the main canvas
  mainCanvas:addWidget(sprite)

  function onSceneUpdate()
    -- Rotate sprite by 2° every frame
    sprite:rotate(2)
  end
]]


dofile("class.lua")
dofile("Object3d.lua")
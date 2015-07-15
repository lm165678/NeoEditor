
--dofile("LuaApiPongTest.lua")
-- dofile("LuaApiSDKTest.lua")
-- dofile("LuaSimpleCollisionDetectionTest.lua")

-- dofile("Benchmark.lua")
-- dofile("NativeSDKTest.lua")

require("NeoLua")

local engine2d = NeoLua.Neo2DEngine.getInstance()
engine2d:setEnabled(true)
engine2d:setDefaultFontSize(16)

local winmgr = NeoLua.WindowManager(0,0,0,0,"")
engine2d:getCanvas(0):addWidget(engine2d:addWidget(winmgr))

function createExampleWindow(x,y)
        local inputField = NeoLua.ThemedInputField(10, 40, 200, 20, "");
        local button = NeoLua.ThemedButton(10, 10, 120, 20, "This is a button!")
        local label = NeoLua.Label(10, 70, 0, 30, "This is a label!")

        local container = NeoLua.Window(x,y,400,300,"Window title!")
        container:addWidget(button)
        container:addWidget(inputField)
        container:addWidget(label)

		winmgr:addWindow(container)

        button:setFontSize(14)
        button:setScriptCallback("buttonCallback")

        return container
end

function createSettingsWindow(x,y)
        local button = NeoLua.ThemedButton(50, 10, 120, 20, "Flip Ortho")
        local inputField = NeoLua.ThemedInputField(50, 40, 200, 20, "100");
        local label = NeoLua.Label(10, 40, 0, 20, "FOV: ")
        local setFovButton = NeoLua.ThemedButton(50, 70, 120, 20, "Set FOV")

        local container = NeoLua.Window(x,y,300,150,"Camera Settings")
        container:addWidget(button)
        container:addWidget(inputField)
        container:addWidget(label)
	container:addWidget(setFovButton)

	winmgr:addWindow(container)

        button:setFontSize(14)
        button:setScriptCallback("flipOrthoCallback")
        setFovButton:setScriptCallback("setFovCallback")

	local win = {}
	win.window = container
	win.inputField = inputField

        return win
end

-- win1 = createExampleWindow(500,100)
settingsWindow = createSettingsWindow(10,50)

function buttonCallback()
        print("Callback!")
		createExampleWindow(math.random(0, 100), math.random(0,100))
		-- inputField:setLabel(inputField:getLabel() .. " BUTTON PRESS ")
end

local engine = NeoLua.NeoEngine.getInstance()
local input = engine:getInputContext()
local scene = engine:getLevel():getCurrentScene()

local cam = scene:getObjectByName("Light")
local teapot = scene:getObjectByName("Teapot")
local sphere = scene:getObjectByName("Sphere")

function flipOrthoCallback()
	local camera = scene:getCurrentCamera()
	camera:enableOrtho(not camera:isOrtho())
end

function setFovCallback()
	local camera = scene:getCurrentCamera()
	camera:setFov(tonumber(settingsWindow.inputField:getLabel()))
end

function onSceneUpdate(delta)

        sphere:rotate(NeoLua.Vector3(0,0,1), 10*delta)
        teapot:rotate(NeoLua.Vector3(0,0,1), 10*delta)

        if input:isKeyPressed("UP") then
                cam:setPosition(cam:getPosition() + NeoLua.Vector3(0,0,1))
        end

        if input:isKeyPressed("DOWN") then
                cam:setPosition(cam:getPosition() + NeoLua.Vector3(0,0,-1))
        end

        if input:isKeyPressed("LEFT") then
                cam:setPosition(cam:getPosition() + NeoLua.Vector3(-1,0,0))
        end

        if input:isKeyPressed("RIGHT") then
                cam:setPosition(cam:getPosition() + NeoLua.Vector3(1,0,0))
        end
end

REPENTOGON = true

collectgarbage("generational")

local defaultCallbackMeta = {
	__matchParams = function(a, b)
		return not a or not b or a == -1 or b == -1 or a == b
	end
}

local debug_getinfo = debug.getinfo

local callbackIDToName = {}
for k, v in pairs(ModCallbacks) do
	callbackIDToName[v] = k
end

local function checkInteger(val)
	if math.type(val) ~= "integer" then
		return "bad return type (number has no integer representation)"
	end
end

local function checkTableSizeFunction(size)
	return function(val)
		local tablesize = 0
		for i, tabletype in pairs(val) do 
			tablesize = i
		end
		
		if tablesize > size then
			return "bad return table length (" .. tostring(size) .. " expected, got " .. tostring(tablesize) .. ")"
		end
	end
end

local function checkTableTypeFunction(typestrings)
	return function(tbl)
		local tablesize = 0
		for i, tabletype in pairs(tbl) do 
			tablesize = i
		end
		
		if tablesize > #typestrings then
			return "bad return table length (" .. tostring(size) .. " expected, got " .. tostring(tablesize) .. ")"
		end
		
		for i, param in pairs(tbl) do
			local paramType = type(param)
			
			if paramType == "number" and math.type(param) == "integer" then
				paramType = "integer"
			end

			if paramType ~= typestrings[i] then
				return "bad return type for table value #" .. tostring(i) .. " (" .. typestrings[i] .. " expected, got " .. paramType .. ")"
			end
		end
	end
end

local function backEnum(enum, id)
	for k, v in pairs(enum) do
		if v == id then
			return k
		end
	end
end

local typecheckFunctions = {
	[ModCallbacks.MC_PRE_ADD_COLLECTIBLE] = {
		["table"] = checkTableTypeFunction({"integer", "integer", "boolean", "integer", "integer"}),
		["number"] = checkInteger
	},
	[ModCallbacks.MC_PRE_SFX_PLAY] = {
		["table"] = checkTableTypeFunction({"integer", "number", "integer", "boolean", "number", "number"}),
		["boolean"] = true
	},
	[ModCallbacks.MC_INPUT_ACTION] = {
		["number"] = function(ret, retType, entity, hook)
			if hook ~= InputHook.GET_ACTION_VALUE then
				return "bad return type for hook " .. backEnum(InputHook, hook) .. " (boolean expected, got number)"
			elseif ret < 0 or ret > 1 then
				return "bad return value for hook GET_ACTION_VALUE (number must be within range 0-1)"
			end
		end,
		["boolean"] = function(ret, retType, entity, hook)
			if hook == InputHook.GET_ACTION_VALUE then
				return "bad return type for hook GET_ACTION_VALUE (number expected, got boolean)"
			end
		end
	},
	[ModCallbacks.MC_EXECUTE_CMD] = {}, -- returning any value causes the game to crash
	[ModCallbacks.MC_PRE_ENTITY_SPAWN] = {
		["table"] = checkTableSizeFunction(4)
	},
	[ModCallbacks.MC_POST_PICKUP_SELECTION] = {
		["table"] = checkTableSizeFunction(2)
	},
	[ModCallbacks.MC_PRE_ROOM_ENTITY_SPAWN] = {
		["table"] = checkTableTypeFunction({"integer", "integer", "integer"})
	},
	[ModCallbacks.MC_USE_ITEM] = {
		["table"] = true,
		["boolean"] = true,
	},
	[ModCallbacks.MC_GET_SHADER_PARAMS] = {
		["table"] = true
	},
}

local boolCallbacks = {
	ModCallbacks.MC_PRE_USE_ITEM,
	ModCallbacks.MC_ENTITY_TAKE_DMG,
	ModCallbacks.MC_PRE_FAMILIAR_COLLISION,
	ModCallbacks.MC_PRE_PICKUP_COLLISION,
	ModCallbacks.MC_PRE_TEAR_COLLISION,
	ModCallbacks.MC_PRE_PROJECTILE_COLLISION,
	ModCallbacks.MC_PRE_BOMB_COLLISION,
	ModCallbacks.MC_PRE_KNIFE_COLLISION,
	ModCallbacks.MC_PRE_PLAYER_COLLISION,
	ModCallbacks.MC_PRE_NPC_COLLISION,
	ModCallbacks.MC_PRE_LASER_COLLISION,
	ModCallbacks.MC_PRE_NPC_UPDATE,
	ModCallbacks.MC_PRE_ENTITY_DEVOLVE,
	ModCallbacks.MC_PRE_SPAWN_CLEAN_AWARD,
}

for _, callback in ipairs(boolCallbacks) do
	typecheckFunctions[callback] = {["boolean"] = true}
end

local intCallbacks = {
	ModCallbacks.MC_POST_CURSE_EVAL,
	ModCallbacks.MC_GET_CARD,
	ModCallbacks.MC_PRE_GET_COLLECTIBLE,
	ModCallbacks.MC_GET_PILL_COLOR,
	ModCallbacks.MC_GET_PILL_EFFECT,
	ModCallbacks.MC_GET_TRINKET,	
}

for _, callback in ipairs(intCallbacks) do
	typecheckFunctions[callback] = {["number"] = checkInteger}
end

local function setExpectedTypes(typeTable)
	local validTypes = {}
	for typ, func in pairs(typeTable) do
		validTypes[#validTypes + 1] = typ
	end
	
	table.sort(validTypes)
	
	local expected = ""
	for i, typ in ipairs(validTypes) do
		if i ~= #validTypes then
			expected = expected .. typ .. ", "
		elseif #validTypes == 1 then
			expected = expected .. typ
		else
			expected = expected .. "or " .. typ
		end
	end
	
	if expected == "" then
		expected = "no return"
	end
	
	typeTable.expectedtypes = expected
end

for callback, typeTable in pairs(typecheckFunctions) do
	setExpectedTypes(typeTable)
end

rawset(Isaac, "SetCallbackTypeCheck", function(callbackID, tbl, noSetExpected)
	typecheckFunctions[callbackID] = tbl
	if not noSetExpected then
		setExpectedTypes(tbl)
	end
end)

rawset(Isaac, "SetCallbackMatchTest", function(callbackID, func)
	local callbacks = Isaac.GetCallbacks(callbackID, true)
	getmetatable(callbacks).__matchParams = func
end)

local function cleanTraceback(level) -- similar to debug.traceback but breaks at xpcall, uses spaces instead of tabs, and doesn't call local functions upvalues
	level = level + 1
	local msg = "Stack Traceback:\n"
	while true do
		local info = debug_getinfo(level, "Sln")
		if not info then break end
		if info.what == "C" then
			if info.name == "xpcall" then break end
			msg = msg .. "  in method " .. tostring(info.name) .. "\n"
		else
			if info.name then
				msg = msg .. "  " .. tostring(info.short_src) .. ":" .. tostring(info.currentline) .. ": in function '" .. tostring(info.name) .. "'\n"
			else
				msg = msg .. "  " .. tostring(info.short_src) .. ":" .. tostring(info.currentline) .. ": in function at line " .. tostring(info.linedefined) .. "\n"
			end
		end
		
		level = level + 1
	end
	
	return msg
end

local err_input = 1
local err_decay = 1500 
local err_hud_opacity = 1
local err_shader_opacity = 1
local err_color = 0
local err_shown = false
local err_bounding_x = nil

local ERR_INPUT_TARGET = 484
local INT_MIN = -2147483647

local err_main_font = Font()
local err_min_font = Font()


local function RenderErrText(name, opacity)
    local main_str = name .. " is causing errors!"
    local detail_str = "Click this message for more info."

    if not err_bounding_x then 
        err_bounding_x = (Isaac.GetScreenWidth() / 2) - (math.max(err_main_font:GetStringWidth(main_str), err_main_font:GetStringWidth(detail_str)) / 2) end

    err_main_font:DrawString(main_str, (Isaac.GetScreenWidth() / 2) - (err_main_font:GetStringWidth(main_str) / 2), 0, KColor(1, err_color, err_color, opacity), 0, false)
    err_min_font:DrawString(detail_str, (Isaac.GetScreenWidth() / 2) - (err_min_font:GetStringWidth(detail_str) / 2), 7, KColor(1, err_color, err_color, opacity), 0 , false)
end


local function logError(callbackID, modName, err)
	local cbName = callbackIDToName[callbackID] or callbackID
	Game():GetConsole():PrintError('"' .. cbName .. '" from "' .. modName .. '" failed: ' ..  err)
	Isaac.DebugString('Error in "' ..cbName .. '" call from "' .. modName .. '": ' .. err) -- this should be replaced with a proper log function so it can have the [INFO] header

        if not err_shown then 	

            local errdisp = RegisterMod("REPENTOGON Error Display", 1)	

            err_main_font:Load("font/pftempestasevencondensed.fnt")	
	    err_min_font:Load("font/luaminioutlined.fnt") 
            local mouse = Sprite()
            mouse:Load("gfx/ui/cursor.anm2", true)


            errdisp:AddPriorityCallback(ModCallbacks.MC_HUD_RENDER, INT_MIN, function()
                if err_input < ERR_INPUT_TARGET then
                    err_color = math.sin((err_input * 200)/ err_decay) / 2 + .5
		    err_input = err_input + 1 
		    err_decay = err_decay + 1
		else
                    err_color = 0
		end

		if err_hud_opacity > 0.3 then err_hud_opacity = err_hud_opacity - (0.7 / ERR_INPUT_TARGET) end
		RenderErrText(modName, err_hud_opacity)


               mouse.Color = Color(1, 1, 1, err_hud_opacity)
               local mouse_pos = Isaac.WorldToScreen(Input.GetMousePosition(true))

               if mouse_pos.X > err_bounding_x and mouse_pos.X < Isaac.GetScreenWidth() - err_bounding_x and mouse_pos.Y < 18 then 
                   mouse.Color = Color(1, 0.5, 0.5, err_hud_opacity) 
                   if Input.IsMouseBtnPressed(Mouse.MOUSE_BUTTON_1) then
                       Game():GetConsole():Show()
                   end
               end

               mouse:Play("Idle")
               mouse:Render(mouse_pos)
            end)
									
	    errdisp:AddPriorityCallback(ModCallbacks.MC_GET_SHADER_PARAMS, INT_MIN, function()
		if err_shader_opacity > 0 then err_shader_opacity = err_shader_opacity - (1 /  ERR_INPUT_TARGET) end
		RenderErrText(modName, err_shader_opacity)
	    end)

        err_shown = true
    end
end

function _RunCallback(callbackID, Param, ...)
    local callbacks = Isaac.GetCallbacks(callbackID)
	if callbacks then
		for _, callback in ipairs(callbacks) do
			local matchFunc = getmetatable(callbacks).__matchParams or defaultCallbackMeta.__matchParams
			if matchFunc(Param, callback.Param) then				
				local status, ret = xpcall(callback.Function, function(msg)
					return msg .. "\n" .. cleanTraceback(2)
				end, callback.Mod, ...)
				if status then
					if ret ~= nil then
						local err
						local typeCheck = typecheckFunctions[callbackID]
						if typeCheck then
							local typ = type(ret)
							if typeCheck[typ] == true then
							elseif typeCheck[typ] then
								err = typeCheck[typ](ret, typ, ...)
							else
								err = "bad return type (" .. typeCheck.expectedtypes .. " expected, got " .. tostring(typ) .. ")"
							end
							
							if err then
								local info = debug_getinfo(callback.Function, "S")
								logError(callbackID, callback.Mod.Name, info.short_src .. ": " .. info.linedefined .. ": " .. err)
							end
						end
						
						if not err then
							return ret
						end
					end
				else
					logError(callbackID, callback.Mod.Name, ret)
				end
			end
		end
	end
end

rawset(Isaac, "RunAdditiveCallback", function(callbackID, value, ...)
	local callbacks = Isaac.GetCallbacks(callbackID)
	for _, callback in ipairs(callbacks) do
		local ret = callback.Function(callback.Mod, value, ...)
		if ret ~= nil then
			value = ret
		end
	end
	return value
end)

Isaac.RunCallbackWithParam = _RunCallback

function Isaac.RunCallback(callbackID, ...)
	return Isaac.RunCallbackWithParam(callbackID, nil, ...)
end

if not _LUADEBUG then
	debug = nil
	os = {
		date = os.date,
		time = os.time,
		clock = os.clock,
		difftime = os.difftime
	}
end
#include <lua.hpp>

#include "CustomImGui.h"
#include "HookSystem.h"
#include "IsaacRepentance.h"
#include "LuaCore.h"

extern CustomImGui customImGui;

static constexpr const char* ImGuiMT = "ImGui";

static int CheckAndSetCallback(lua_State* L, int slot)
{
    if (!lua_isfunction(L, slot) && !lua_isnoneornil(L, slot))
        return luaL_error(L, "Argument %d is not a function and not nil", (slot - 1));
    if (!lua_isfunction(L, slot)) {
        return 0;
    }
    lua_pushvalue(L, slot); // push function on stack
    return luaL_ref(L, LUA_REGISTRYINDEX); // get unique key
}

static int EvalIDAndParent(lua_State* L, CustomImGui* imGui, const char* id, const char* parentId)
{
    if (!imGui->ElementExists(parentId))
        return luaL_error(L, "Parent Element with id '%s'doesnt exist.", parentId);
    if (imGui->ElementExists(id))
        return luaL_error(L, "Element with id '%s' exists already.", id);
    return 0;
}

static int Lua_CustomImGui(lua_State* L)
{
    Manager* manager = g_Manager;
    CustomImGui** ud = (CustomImGui**)lua_newuserdata(L, sizeof(CustomImGui*));
    *ud = &customImGui;
    luaL_setmetatable(L, ImGuiMT);
    return 1;
}

static int Lua_AddElement(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    int type = (int)luaL_checkinteger(L, 4);
    const char* text = luaL_optstring(L, 5, "");

    if (imGui->ElementExists(id)) {
        return luaL_error(L, "Element with id '%s' exists already.", id);
    }

    bool success = imGui->AddElement(parentId, id, text, type);
    if (!success) {
        return luaL_error(L, "Parent element '%s' not found.", parentId);
    }

    return 1;
}

static int Lua_RemoveElement(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    const char* elementId = luaL_checkstring(L, 2);

    imGui->RemoveElement(elementId);

    return 0;
}

static int Lua_LinkWindowToElement(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    const char* windowId = luaL_checkstring(L, 2);
    const char* elementId = luaL_checkstring(L, 3);

    if (imGui->GetElementById(windowId) == NULL) {
        return luaL_error(L, "No window with id '%s' exists", windowId);
    }

    bool success = imGui->LinkWindowToElement(windowId, elementId);
    if (!success) {
        return luaL_error(L, "Element with id '%s' not found", elementId);
    }

    return 1;
}

static int Lua_CreateMenu(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    const char* id = luaL_checkstring(L, 2);
    const char* text = luaL_checkstring(L, 3);

    if (imGui->ElementExists(id)) {
        return luaL_error(L, "Element with id '%s' exists already.", id);
    }

    bool success = imGui->CreateMenuElement(id, text);
    if (!success) {
        return luaL_error(L, "Error while adding new Menu '%s'", id);
    }

    return 1;
}

static int Lua_RemoveMenu(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    const char* menuId = luaL_checkstring(L, 2);

    imGui->RemoveMenu(menuId);

    return 0;
}

static int Lua_CreateWindow(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    const char* id = luaL_checkstring(L, 2);
    const char* title = luaL_checkstring(L, 3);

    if (imGui->ElementExists(id)) {
        return luaL_error(L, "Element with id '%s' exists already.", id);
    }

    bool success = imGui->CreateWindowElement(id, title);
    if (!success) {
        return luaL_error(L, "Error while adding new Window '%s'", id);
    }

    return 1;
}

static int Lua_RemoveWindow(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    const char* windowId = luaL_checkstring(L, 2);

    imGui->RemoveWindow(windowId);

    return 0;
}

static int Lua_AddCallback(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    const char* parentId = luaL_checkstring(L, 2);
    int type = (int)luaL_checkinteger(L, 3);
    if (!lua_isfunction(L, 4)) {
        return luaL_error(L, "Argument %d is not a function", 4);
    }
    int stackID = CheckAndSetCallback(L, 4);

    bool success = imGui->AddCallback(parentId, type, stackID);
    if (!success) {
        return luaL_error(L, "No element '%s' found.", parentId);
    }

    return 1;
}

static int Lua_RemoveCallback(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    const char* parentId = luaL_checkstring(L, 2);
    int type = (int)luaL_checkinteger(L, 3);

    bool success = imGui->RemoveCallback(parentId, type);
    if (!success) {
        return luaL_error(L, "No element '%s' found.", parentId);
    }

    return 1;
}

static int Lua_UpdateText(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    const char* id = luaL_checkstring(L, 2);
    const char* text = luaL_checkstring(L, 3);

    bool success = imGui->UpdateText(id, text);
    if (!success) {
        return luaL_error(L, "No element with id '%s' found.", id);
    }

    return 1;
}

static int Lua_AddButton(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    const char* text = luaL_optstring(L, 4, "");
    int stackID = CheckAndSetCallback(L, 5);
    bool isSmall = lua_toboolean(L, 6);

    EvalIDAndParent(L, imGui, id, parentId);

    int type = static_cast<int>(IMGUI_ELEMENT::Button);
    if (isSmall)
        type = static_cast<int>(IMGUI_ELEMENT::SmallButton);

    imGui->AddElement(parentId, id, text, type);

    if (lua_isfunction(L, 5)) {
        imGui->AddCallback(id, static_cast<int>(IMGUI_CALLBACK::Clicked), stackID);
    }

    return 1;
}

static int Lua_AddInputInteger(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    IntData data = IntData();
    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    const char* text = luaL_optstring(L, 4, "");
    int stackID = CheckAndSetCallback(L, 5);
    data.setDefaultVal((int)luaL_optinteger(L, 6, data.defaultVal));
    data.step = (int)luaL_optinteger(L, 7, data.step);
    data.stepFast = (int)luaL_optinteger(L, 8, data.stepFast);

    EvalIDAndParent(L, imGui, id, parentId);

    int type = static_cast<int>(IMGUI_ELEMENT::InputInt);

    imGui->AddElement(parentId, id, text, type);
    Element* createdElement = imGui->GetElementById(id);

    createdElement->AddData(data);

    if (lua_isfunction(L, 5)) {
        imGui->AddCallback(id, static_cast<int>(IMGUI_CALLBACK::Edited), stackID);
    }
    return 1;
}

static int Lua_AddInputFloat(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    FloatData data = FloatData();
    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    const char* text = luaL_optstring(L, 4, "");
    int stackID = CheckAndSetCallback(L, 5);
    data.setDefaultVal((float)luaL_optnumber(L, 6, data.defaultVal));
    data.step = (float)luaL_optnumber(L, 7, data.step);
    data.stepFast = (float)luaL_optnumber(L, 8, data.stepFast);

    EvalIDAndParent(L, imGui, id, parentId);

    int type = static_cast<int>(IMGUI_ELEMENT::InputFloat);

    imGui->AddElement(parentId, id, text, type);
    Element* createdElement = imGui->GetElementById(id);

    createdElement->AddData(data);

    if (lua_isfunction(L, 5)) {
        imGui->AddCallback(id, static_cast<int>(IMGUI_CALLBACK::Edited), stackID);
    }
    return 1;
}

static int Lua_AddDragInteger(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    IntData data = IntData();
    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    const char* text = luaL_optstring(L, 4, "");
    int stackID = CheckAndSetCallback(L, 5);
    data.setDefaultVal((int)luaL_optinteger(L, 6, data.defaultVal));
    data.speed = (float)luaL_optnumber(L, 7, data.speed);
    data.minVal = (int)luaL_optinteger(L, 8, data.minVal);
    data.maxVal = (int)luaL_optinteger(L, 9, data.maxVal);
    data.formatting = luaL_optstring(L, 10, data.formatting);

    EvalIDAndParent(L, imGui, id, parentId);

    int type = static_cast<int>(IMGUI_ELEMENT::DragInt);

    imGui->AddElement(parentId, id, text, type);
    Element* createdElement = imGui->GetElementById(id);

    createdElement->AddData(data);

    if (lua_isfunction(L, 5)) {
        imGui->AddCallback(id, static_cast<int>(IMGUI_CALLBACK::Edited), stackID);
    }
    return 1;
}

static int Lua_AddDragFloat(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    FloatData data = FloatData();
    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    const char* text = luaL_optstring(L, 4, "");
    int stackID = CheckAndSetCallback(L, 5);
    data.setDefaultVal((float)luaL_optnumber(L, 6, data.defaultVal));
    data.speed = (float)luaL_optnumber(L, 7, data.speed);
    data.minVal = (float)luaL_optnumber(L, 8, data.minVal);
    data.maxVal = (float)luaL_optnumber(L, 9, data.maxVal);
    data.formatting = luaL_optstring(L, 10, data.formatting);

    EvalIDAndParent(L, imGui, id, parentId);

    int type = static_cast<int>(IMGUI_ELEMENT::DragFloat);

    imGui->AddElement(parentId, id, text, type);
    Element* createdElement = imGui->GetElementById(id);

    createdElement->AddData(data);

    if (lua_isfunction(L, 5)) {
        imGui->AddCallback(id, static_cast<int>(IMGUI_CALLBACK::Edited), stackID);
    }
    return 1;
}

static int Lua_AddSliderInteger(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    IntData data = IntData();
    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    const char* text = luaL_optstring(L, 4, "");
    int stackID = CheckAndSetCallback(L, 5);
    data.setDefaultVal((int)luaL_optinteger(L, 6, data.defaultVal));
    data.minVal = (int)luaL_optinteger(L, 7, data.minVal);
    data.maxVal = (int)luaL_optinteger(L, 8, data.maxVal);
    data.formatting = luaL_optstring(L, 9, data.formatting);

    EvalIDAndParent(L, imGui, id, parentId);

    int type = static_cast<int>(IMGUI_ELEMENT::SliderInt);

    imGui->AddElement(parentId, id, text, type);
    Element* createdElement = imGui->GetElementById(id);

    createdElement->AddData(data);

    if (lua_isfunction(L, 5)) {
        imGui->AddCallback(id, static_cast<int>(IMGUI_CALLBACK::Edited), stackID);
    }
    return 1;
}

static int Lua_AddSliderFloat(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);

    FloatData data = FloatData();
    const char* parentId = luaL_checkstring(L, 2);
    const char* id = luaL_checkstring(L, 3);
    const char* text = luaL_optstring(L, 4, "");
    int stackID = CheckAndSetCallback(L, 5);
    data.setDefaultVal((float)luaL_optnumber(L, 6, data.defaultVal));
    data.minVal = (float)luaL_optnumber(L, 7, data.minVal);
    data.maxVal = (float)luaL_optnumber(L, 8, data.maxVal);
    data.formatting = luaL_optstring(L, 9, data.formatting);

    EvalIDAndParent(L, imGui, id, parentId);

    int type = static_cast<int>(IMGUI_ELEMENT::SliderFloat);

    imGui->AddElement(parentId, id, text, type);
    Element* createdElement = imGui->GetElementById(id);

    createdElement->AddData(data);

    if (lua_isfunction(L, 5)) {
        imGui->AddCallback(id, static_cast<int>(IMGUI_CALLBACK::Edited), stackID);
    }
    return 1;
}

extern bool menuShown;
static int Lua_ImGuiShow(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    menuShown = true;

    return 0;
}

static int Lua_ImGuiHide(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    menuShown = false;

    return 0;
}

static int Lua_ImGuiReset(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    imGui->Reset();

    return 0;
}

static int Lua_ElementExists(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    const char* id = luaL_checkstring(L, 2);

    lua_pushboolean(L, imGui->ElementExists(id));

    return 1;
}

static int Lua_ImGuiSetVisible(lua_State* L)
{
    CustomImGui* imGui = *lua::GetUserdata<CustomImGui**>(L, 1, ImGuiMT);
    const char* elementId = luaL_checkstring(L, 2);
    bool newState = lua_toboolean(L, 3);

    bool success = imGui->SetVisible(elementId, newState);

    if (!success) {
        return luaL_error(L, "Element with id '%s' not found", elementId);
    }

    return 0;
}

static void RegisterCustomImGui(lua_State* L)
{
    lua_getglobal(L, "Isaac");
    lua_pushstring(L, "GetImGui");
    lua_pushcfunction(L, Lua_CustomImGui);
    lua_rawset(L, -3);
    lua_pop(L, 1);

    luaL_newmetatable(L, ImGuiMT);
    lua_pushstring(L, "__index");
    lua_pushvalue(L, -2);
    lua_settable(L, -3);

    luaL_Reg functions[] = {
        { "AddCallback", Lua_AddCallback },
        { "RemoveCallback", Lua_RemoveCallback },
        { "AddElement", Lua_AddElement },
        { "RemoveElement", Lua_RemoveElement },
        { "CreateMenu", Lua_CreateMenu },
        { "RemoveMenu", Lua_RemoveMenu },
        { "CreateWindow", Lua_CreateWindow },
        { "RemoveWindow", Lua_RemoveWindow },
        { "LinkWindowToElement", Lua_LinkWindowToElement },
        { "SetVisible", Lua_ImGuiSetVisible },
        { "ElementExists", Lua_ElementExists },
        { "UpdateText", Lua_UpdateText },
        { "AddButton", Lua_AddButton },
        { "AddInputInteger", Lua_AddInputInteger },
        { "AddInputFloat", Lua_AddInputFloat },
        { "AddDragInteger", Lua_AddDragInteger },
        { "AddDragFloat", Lua_AddDragFloat },
        { "AddSliderInteger", Lua_AddSliderInteger },
        { "AddSliderFloat", Lua_AddSliderFloat },
        { "Reset", Lua_ImGuiReset },
        { "Show", Lua_ImGuiShow },
        { "Hide", Lua_ImGuiHide },
        { NULL, NULL }
    };

    luaL_setfuncs(L, functions, 0);
    lua_pop(L, 1);
}

HOOK_METHOD(LuaEngine, RegisterClasses, ()->void)
{
    super();
    lua_State* state = g_LuaEngine->_state;
    lua::LuaStackProtector protector(state);
    RegisterCustomImGui(state);
}

cmake_minimum_required(VERSION 3.13.0)

project(RepExtender)

include_directories(${CMAKE_SOURCE_DIR}/include "${CMAKE_SOURCE_DIR}/include/LuaBridge" "${CMAKE_SOURCE_DIR}/libs/lua-5.3.3/src" "${CMAKE_SOURCE_DIR}/libs/LuaSource-2.0/Source/LuaBridge")

FILE(GLOB LUA_SRC ${CMAKE_SOURCE_DIR}/libs/lua-5.3.3/src/*.c)
list(REMOVE_ITEM LUA_SRC "${CMAKE_SOURCE_DIR}/libs/lua-5.3.3/src/luac.c")
add_library(Lua5.3.3r SHARED ${LUA_SRC})

add_executable(lua "${CMAKE_SOURCE_DIR}/libs/lua-5.3.3/src/lua.c")
target_link_libraries (lua Lua5.3.3r)

FILE(GLOB LUA_LFS_SRC ${CMAKE_SOURCE_DIR}/libs/luafilesystem/src/*.c)
add_library(lfs SHARED ${LUA_LFS_SRC})
target_link_libraries(lfs Lua5.3.3r)

FILE (GLOB LUA_LPEG_SRC ${CMAKE_SOURCE_DIR}/libs/lpeg-1.0.2/*.c)
add_library(lpeg SHARED ${LUA_LPEG_SRC})
target_link_libraries(lpeg Lua5.3.3r)

FILE(GLOB ZHL_FILES ${CMAKE_SOURCE_DIR}/libzhl/functions/*.zhl)
add_custom_target(ZHL COMMAND lua parsefuncs.lua WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/libzhlgen" DEPENDS ${ZHL_FILES})
add_dependencies(ZHL lpeg lfs)

FILE(GLOB ZHL_SRC ${CMAKE_SOURCE_DIR}/libzhl/*.cpp ${CMAKE_SOURCE_DIR}/libzhl/IsaacRepentance.cpp)
add_library(libzhl SHARED ${ZHL_SRC})

FILE(GLOB LAUNCHER_SRC ${CMAKE_SOURCE_DIR}/launcher/*.cpp)
add_library(dsound SHARED ${LAUNCHER_SRC})

FILE(GLOB MODTEST_SRC ${CMAKE_SOURCE_DIR}/modtest/*.cpp)
add_library(zhlModTest SHARED ${MODTEST_SRC})

add_dependencies(libzhl ZHL)

target_link_libraries(zhlModTest Lua5.3.3r libzhl)
target_link_libraries(libzhl Lua5.3.3r)
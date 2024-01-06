﻿/* This is saved as UTF-8 with BOM(code page 65001) */
#ifndef I
#define I(ITEM, TRANSLATE)
#endif

//=========== Main Menu Bar ==========
// I(BAR_TOOLS, ICON_FA_SCREWDRIVER_WRENCH " Tools") // non-utf8 version is no problem here for en_us
I(BAR_TOOLS, ICON_U8_FA_SCREWDRIVER_WRENCH u8" Tools")
I(BAR_DEBUG_CONSOLE, ICON_U8_FA_TERMINAL u8" Debug Console")
I(BAR_LOG_VIEWER, ICON_U8_FA_NEWSPAPER u8" Log Viewer")
I(BAR_GAME_OPTIONS, ICON_U8_FA_GEARS u8" Game Options")
I(BAR_PERFORMANCE, ICON_U8_FA_GAUGE_HIGH u8" Performance")
I(BAR_STYLE_EDITOR, ICON_U8_FA_PENCIL u8" Style Editor")

I(DEAR_IMGUI_STYLE_EDITOR_WIN_NAME, u8"Dear ImGui Style Editor")

//=========== Console Mega =============

I(CONSOLE_WINDOW_NAME, "Console")

I(CONSOLE_REPENTOGON_CONSOLE, "REPENTOGON Console\n")
I(CONSOLE_CANT_BE_USED_IF_NOT_IN_GAME, "[ERROR] %s can't be used if not in-game!")
I(CONSOLE_HELP_OUTSIDE_GAME_HINT, "(Only commands enabled to show outside of the game will appear right now.)\n")
I(CONSOLE_NO_MACRO_HINT, "No macro with that name.\n")

I(CONSOLE_CMD_HINT, u8"Type your command here (\"help\" for help)")

I(CONSOLE_GOTO_HINT_default, u8"default")
I(CONSOLE_GOTO_HINT_shop, u8"shop")
I(CONSOLE_GOTO_HINT_error, u8"error")
I(CONSOLE_GOTO_HINT_treasure, u8"treasure")
I(CONSOLE_GOTO_HINT_boss, u8"boss")
I(CONSOLE_GOTO_HINT_miniboss, u8"miniboss")
I(CONSOLE_GOTO_HINT_secret, u8"secret")
I(CONSOLE_GOTO_HINT_supersecret, u8"supersecret")
I(CONSOLE_GOTO_HINT_arcade, u8"arcade")
I(CONSOLE_GOTO_HINT_curse, u8"curse")
I(CONSOLE_GOTO_HINT_challenge, u8"challenge")
I(CONSOLE_GOTO_HINT_library, u8"library")
I(CONSOLE_GOTO_HINT_sacrifice, u8"sacrifice")
I(CONSOLE_GOTO_HINT_devil, u8"devil")
I(CONSOLE_GOTO_HINT_angel, u8"angel")
I(CONSOLE_GOTO_HINT_itemdungeon, u8"itemdungeon")
I(CONSOLE_GOTO_HINT_bossrush, u8"bossrush")
I(CONSOLE_GOTO_HINT_isaacs, u8"isaacs")
I(CONSOLE_GOTO_HINT_barren, u8"barren")
I(CONSOLE_GOTO_HINT_chest, u8"chest")
I(CONSOLE_GOTO_HINT_dice, u8"dice")
I(CONSOLE_GOTO_HINT_blackmarket, u8"blackmarket")
I(CONSOLE_GOTO_HINT_greedexit, u8"greedexit")
I(CONSOLE_GOTO_HINT_planetarium, u8"planetarium")
I(CONSOLE_GOTO_HINT_teleporter, u8"teleporter")
I(CONSOLE_GOTO_HINT_teleporterexit, u8"teleporterexit")
I(CONSOLE_GOTO_HINT_secretexit, u8"secretexit")
I(CONSOLE_GOTO_HINT_blue, u8"blue")
I(CONSOLE_GOTO_HINT_ultrasecret, u8"ultrasecret")

I(CONSOLE_DEBUG_HINT_1, u8"Entity Positions")
I(CONSOLE_DEBUG_HINT_2, u8"Grid")
I(CONSOLE_DEBUG_HINT_3, u8"Infinite HP")
I(CONSOLE_DEBUG_HINT_4, u8"High Damage")
I(CONSOLE_DEBUG_HINT_5, u8"Show Room Info")
I(CONSOLE_DEBUG_HINT_6, u8"Show Hitspheres")
I(CONSOLE_DEBUG_HINT_7, u8"Show Damage Values")
I(CONSOLE_DEBUG_HINT_8, u8"Infinite Item Charges")
I(CONSOLE_DEBUG_HINT_9, u8"High Luck")
I(CONSOLE_DEBUG_HINT_10, u8"Quick Kill")
I(CONSOLE_DEBUG_HINT_11, u8"Grid Info")
I(CONSOLE_DEBUG_HINT_12, u8"Player Item Info")
I(CONSOLE_DEBUG_HINT_13, u8"Show Grid Collision Points")
I(CONSOLE_DEBUG_HINT_14, u8"Show Lua Memory Usage")

I(CONSOLE_COMBO_HINT_0, "Treasure")
I(CONSOLE_COMBO_HINT_1, "Shop")
I(CONSOLE_COMBO_HINT_2, "Boss")
I(CONSOLE_COMBO_HINT_3, "Devil")
I(CONSOLE_COMBO_HINT_4, "Angel")
I(CONSOLE_COMBO_HINT_5, "Secret")
I(CONSOLE_COMBO_HINT_6, "Library")
I(CONSOLE_COMBO_HINT_7, "Challenge")
I(CONSOLE_COMBO_HINT_8, "Golden Chest")
I(CONSOLE_COMBO_HINT_9, "Red Chest")
I(CONSOLE_COMBO_HINT_10, "Beggar")
I(CONSOLE_COMBO_HINT_11, "Demon Beggar")
I(CONSOLE_COMBO_HINT_12, "Curse")
I(CONSOLE_COMBO_HINT_13, "Key Master")
I(CONSOLE_COMBO_HINT_14, "Boss Rush")
I(CONSOLE_COMBO_HINT_15, "Dungeon")

//=========== Console Mega Commands ==========
I(CONSOLE_ACHIEVEMENT_DESC, u8"Unlocks achievements")
I(CONSOLE_ACHIEVEMENT_HELP, u8"Unlocks achievements")

I(CONSOLE_ADD_PLAYER_DESC, u8"Spawns a new player")
I(CONSOLE_ADD_PLAYER_HELP, u8"Spawns a new player entity. On default, it spawns Isaac with controller ID 0.\nPlayer ID -1 lets you take control of a random enemy in the room.\nExample:\n(addplayer 7 1) Spawns Azazel and can be controlled with the second input device (controller 1 in most cases)")

I(CONSOLE_CHALLENGE_DESC, u8"Start a challenge run")
I(CONSOLE_CHALLENGE_HELP, u8"Stops the current run and starts a new run on a random seed with the given challenge ID.\nExample:\n(challenge 20) will start a new Purist challenge run.\n")

I(CONSOLE_CLEAR_DESC, u8"Clear the debug console")
I(CONSOLE_CLEAR_HELP, u8"Clears all text currently displayed in the debug console. Only the line \"Repentance Console\" will remain.")

I(CONSOLE_CLEARCACHE_DESC, u8"Clear the sprite cache")
I(CONSOLE_CLEARCACHE_HELP, u8"Clears the game's sprite cache. This can be useful for trying to deal with memory issues.\nThis also has the side effect of reloading modded sprites without needing a full game restart.")

I(CONSOLE_CLEARSEEDS_DESC, u8"Clear easter egg seeds in the current run")
I(CONSOLE_CLEARSEEDS_HELP, u8"Clears any \"special\" seed effects in the current run.\nExample:\nThe seed effect GFVE LLLL is applied in a run. Running clearseeds will remove this effect.")

I(CONSOLE_COMBO_DESC, u8"Give items from a specified pool")
I(CONSOLE_COMBO_HELP, u8"Gives a specified number of items from a specified item pool.\nExample:\n(combo 4.6) will give six random items from the Angel item pool.\nNo, I don't know why they made a bespoke ID system for this one (1) command.")

I(CONSOLE_COPY_DESC, u8"Copy previous commands to clipboard")
I(CONSOLE_COPY_HELP, u8"Copies a specified amount of previous console commands to the system clipboard.\nExample:\n(copy 3) will copy the previous three commands.")

I(CONSOLE_COSTUMETEST_DESC, u8"Give the player random costumes")
I(CONSOLE_COSTUMETEST_HELP, u8"Gives the player a specified amount of random costumes.\nExample:\n(costumetest 34) will give the player 34 random costumes.")

I(CONSOLE_CURSE_DESC, u8"Add curses to the current run")
I(CONSOLE_CURSE_HELP, u8"Permanently (until overridden) adds curses to the run. This command uses a bitmask- the curse with an ID of 1 is 1, 2 is 2, 3 is 4, 4 is 8, and so on. In this manner, desired curse ID's are tallied up and multiple can be enabled simultaneously.\nExample:\n(curse 96) will enable Curse of the Blind and Curse of the Maze simultaneously.")

I(CONSOLE_CUTSCENE_DESC, u8"Play a cutscene")
I(CONSOLE_CUTSCENE_HELP, u8"Immediately plays the specified cutscenne.\nExample:\n(cutscene 1) will immediately play the game's intro.")

I(CONSOLE_DEBUG_DESC, u8"Enable a debug flag")
I(CONSOLE_DEBUG_HELP, u8"Enables the specified debug flag.\nExample:\n(debug 3) will grant the player infinite HP.")

I(CONSOLE_DELIRIOUS_DESC, u8"Force Delirious to be a certain boss")
I(CONSOLE_DELIRIOUS_HELP, u8"Overrides the next boss the Delirious item will become.\nExample:\n(delirious 3) will force Delirious to be a Chub.")

I(CONSOLE_EGGS_DESC, u8"Unlock all easter egg seeds")
I(CONSOLE_EGGS_HELP, u8"PERMANENTLY unlocks all easter eggs in this save file.")

I(CONSOLE_FORCEROOM_DESC, u8"Force a room to be used in level generator")
I(CONSOLE_FORCEROOM_HELP, u8"Allows to set any room as \"forced room\". Said room gets weight of 1000, making it more likely to appear on floor with reseed command.")

I(CONSOLE_FULLRESTART_DESC, u8"Closes and reopens the game")
I(CONSOLE_FULLRESTART_HELP, u8"Closes and reopens the game")

I(CONSOLE_GIVEITEM_DESC, u8"Give the character items, trinkets, cards, and pills")
I(CONSOLE_GIVEITEM_HELP, u8"Gives the main player items, trinkets, cards and pills. These can either be by name or by prefix. Prefixes are (c) for items, (t) for trinkets, (p) for pills, and (k) for cards. Most pocket items count as cards.\nThis command also has shorthand which is just (g).\nExamples:\n(giveitem c1) will give the player The Sad Onion.\n(giveitem t1) will give the player Gulp!\n(giveitem p1) will give the player a Bad Trip pill.\n(giveitem k1) will give the player 0 - The Fool.")

I(CONSOLE_GIVEITEM2_DESC, u8"Give player 2 items, trinkets, cards, and pills")
I(CONSOLE_GIVEITEM2_HELP, u8"Gives the second player items, trinkets, cards and pills. These can either be by name or by prefix. Prefixes are (c) for items, (t) for trinkets, (p) for pills, and (k) for cards. Most pocket items count as cards.\nThis command also has shorthand which is just (g).\nExamples:\n(giveitem2 c1) will give the player The Sad Onion.\n(giveitem2 t1) will give the player Gulp!\n(giveitem2 p1) will give the player a Bad Trip pill.\n(giveitem2 k1) will give the player 0 - The Fool.")

I(CONSOLE_GOTO_DESC, u8"Teleport to a new room")
I(CONSOLE_GOTO_HELP, u8"Teleports the character to a new room. Use (d) for a standard room, (s) for a special room, or three numbers to teleport to an existing room on the floor.\nExample:\n(goto s.boss.1010) will go to a Monstro fight.")

I(CONSOLE_GRIDSPAWN_DESC, u8"Spawn a grid entity")
I(CONSOLE_GRIDSPAWN_HELP, u8"Spawns a new grid entity of the given ID at a random place in the room.")

I(CONSOLE_HELP_DESC, u8"Get info about commands")
I(CONSOLE_HELP_HELP, u8"Retrieve further info about a command and its syntax.")

I(CONSOLE_LISTCOLLECTIBLES_DESC, u8"List current items")
I(CONSOLE_LISTCOLLECTIBLES_HELP, u8"Lists the items the player currently has.")

I(CONSOLE_LOCKACHIEVEMENT_DESC, u8"Locks achievements")
I(CONSOLE_LOCKACHIEVEMENT_HELP, u8"Locks achievements")

I(CONSOLE_LUA_DESC, u8"Run Lua code")
I(CONSOLE_LUA_HELP, u8"Runs the given Lua code immediately. Anything which would work in a standard file will work here.\nThis command also has shorthand which is just (l).")

I(CONSOLE_LUAMEM_DESC, u8"Display lua memory usage")
I(CONSOLE_LUAMEM_HELP, u8"Displays the currently used RAM of LUA.")

I(CONSOLE_LUAMOD_DESC, u8"Reload a Lua mod")
I(CONSOLE_LUAMOD_HELP, u8"Reloads Lua code for the given mod folder.\nExample:\n(luamod testmod) will reload Lua code for the mod in the folder \"testmod\".")

I(CONSOLE_LUARESET_DESC, u8"[EXPERIMENTAL] Reset the Lua context")
I(CONSOLE_LUARESET_HELP, u8"Destroys the current Lua context and recreates it from scratch. This is mostly a backend command meant to help sync up networked play.\nThis has Unforeseen Consequences if done in-game, please only do this on the menu unless you know what you're doing. Please?")

I(CONSOLE_LUARUN_DESC, u8"Run a Lua file")
I(CONSOLE_LUARUN_HELP, u8"Runs a given Lua file immediately.\nExample:\n(luarun mods/test/test.lua) would run \"test.lua\" inside the \"test\" mod folder.")

I(CONSOLE_MACRO_DESC, u8"Trigger a set of commands")
I(CONSOLE_MACRO_HELP, u8"Run a set of commands in a specified order. These are effectively shortcuts. Refer to autocomplete for a list of macro commands.")

I(CONSOLE_METRO_DESC, u8"Force Metronome to be a certain item")
I(CONSOLE_METRO_HELP, u8"Overrides the next item Metronome will become.\nExample:\n(metro c1) will force Metronome to become The Sad Onion.")

I(CONSOLE_NETDELAY_DESC, u8"Change network delay")
I(CONSOLE_NETDELAY_HELP, u8"Changes network delay to a specified value. Can be useful if you see stutters during online gameplay.")

I(CONSOLE_NETSTART_DESC, u8"Initialize online coop")
I(CONSOLE_NETSTART_HELP, u8"Connects player(s) with specified Steam ID to your game (online multiplayer). Allows up to 4 players.\nExample:\nnetstart <steam_user_id1> <steam_user_id2>")

I(CONSOLE_PLAYSFX_DESC, u8"Play a sound effect")
I(CONSOLE_PLAYSFX_HELP, u8"Plays a sound effect immediately.\nExample:\n(playsfx 187) will play an incorrect buzzer.")

I(CONSOLE_PROF_DESC, u8"[BROKEN] Start profiling")
I(CONSOLE_PROF_HELP, u8"Supposed to log information to a CSV. Blame Nicalis!")

I(CONSOLE_PROFSTOP_DESC, u8"[BROKEN] Stop profiling")
I(CONSOLE_PROFSTOP_HELP, u8"Supposed to stop profiling but profiling is broken because we can't have nice things.")

I(CONSOLE_REMOVE_DESC, u8"Remove an item")
I(CONSOLE_REMOVE_HELP, u8"Removes an item from the player immediately. Accepts the same syntax as give, look at that command's help for more info.")

I(CONSOLE_REMOVE2_DESC, u8"Remove an item")
I(CONSOLE_REMOVE2_HELP, u8"Removes an item from the second player immediately. Accepts the same syntax as give, look at that command's help for more info.")

I(CONSOLE_RELOADFX_DESC, u8"Reload floor overlays")
I(CONSOLE_RELOADFX_HELP, u8"Reloads the current floor's effects.")

I(CONSOLE_RELOADSHADERS_DESC, u8"Reload in-game shaders")
I(CONSOLE_RELOADSHADERS_HELP, u8"Reloads any currently loaded shaders.")

I(CONSOLE_RELOADWISPS_DESC, u8"Reload wisps")
I(CONSOLE_RELOADWISPS_HELP, u8"Reloads wisps spawned by Book of Virtues and locusts spawned by Abyss.")

I(CONSOLE_REPEAT_DESC, u8"Repeat prior commands")
I(CONSOLE_REPEAT_HELP, u8"Repeats the previously entered command X amount of times.\nExample:\n(giveitem 1) is used to give the player The Sad Onion. (repeat 5) is then used to give the player The Sad Onion five more times.")

I(CONSOLE_RESEED_DESC, u8"Reseed the current floor")
I(CONSOLE_RESEED_HELP, u8"Reseeds the current floor, generating a brand new layout for it.")

I(CONSOLE_RESTART_DESC, u8"Restart on a new run")
I(CONSOLE_RESTART_HELP, u8"Restarts the game on a new run. Accepts an optional argument which is the character ID.\nExample:\n(restart 3) starts a new run as Judas.")

I(CONSOLE_RESTOCK_DESC, u8"Restocks all shops")
I(CONSOLE_RESTOCK_HELP, u8"Restocks all shops.")

I(CONSOLE_REWIND_DESC, u8"Reset game to last room state")
I(CONSOLE_REWIND_HELP, u8"Makes the game forget about the changes in current room and teleports Isaac back to previous room. Can be used to fix desynchronization issues if you use this command in a room where it happened. (Glowing Hourglass-like effect)")

I(CONSOLE_SEED_DESC, u8"Start a new run with the given seed")
I(CONSOLE_SEED_HELP, u8"Starts a new run with the given seed.\nExample:\n(seed N1CA L1SY) will start a new run with the seed N1CA L1SY.")

I(CONSOLE_SPAWN_DESC, u8"Spawn an entity")
I(CONSOLE_SPAWN_HELP, u8"Spawns a new entity. Syntax is (type).(variant).(subtype).(champion).\nExample:\n(spawn 5.40.1) will spawn a bomb.")

I(CONSOLE_STAGE_DESC, u8"Go to a stage")
I(CONSOLE_STAGE_HELP, u8"Immediately goes to the specified stage. Accepts (a-d) as modifiers, with (a) corresponding to WOTL alts, (b) corresponding to Afterbirth alts, (c) corresponding to Antibirth alts, and (d) corresponding to Repentance alts.\nExample:\n(stage 4d) will take the player to Ashpit II.")

I(CONSOLE_TIME_DESC, u8"Print game time")
I(CONSOLE_TIME_HELP, u8"Prints the total amount of time passed on the run.")

I(CONSOLE_TESTBOSSPOOL_DESC, u8"Print list of bosses for current floor")
I(CONSOLE_TESTBOSSPOOL_HELP, u8"Prints a list of boss names and percentage chance (100%=10000) for current floor.")

//=========== Game Options =============

I(OPT_RESET_BTN_HINT, "Reset to default value")

I(OPT_OPTIONS, "Options")
I(OPT_SFX_VOLUME, "SFX Volume")
I(OPT_MUSIC_VOLUME, "Music Volume")
I(OPT_MAP_OPACITY, "Map Opacity")
I(OPT_FILTER, "Filter")
I(OPT_FILTER_MARK, "Applies a shader that makes the game look no longer pixelated. Can cause issues with text rendering on screen!")
I(OPT_POP_UPS, "Pop-Ups")
I(OPT_ANNOUNCER_VOICE_MODE, "Announcer Voice Mode")

I(OPT_HUD_HUDS, "HUDs")
I(OPT_HUD_HUD_OFFSET, "HUD Offset")
I(OPT_HUD_FOUND_HUD, "Found HUD")
I(OPT_HUD_FOUND_HUD_MARKER, "Displays the stats of the player on the left side of the screen.")
I(OPT_HUD_CHARGE_BARS, "Chargebars")
I(OPT_HUD_BOSS_HEALTH_BAR_ON_BOTTOM, "Boss Healthbar on bottom")
I(OPT_HUD_EXTRA_HUD, "Extra Hud")
I(OPT_HUD_EXTRA_HUD_MARKER, "Displays collected items of the player on the right side of the screen.")

I(OPT_CONSOLE, "Console")
I(OPT_CONSOLE_ENABLE_DEBUG_CONSOLE, "Enable Debug Console")
I(OPT_CONSOLE_FADED_CONSOLE_DISPLAY,"Faded Console Display")
I(OPT_CONSOLE_SAVE_COMMAND_HISTORY, "Save Command History")
I(OPT_CONSOLE_CONSOLE_FONT, "Console Font")
I(OPT_CONSOLE_ENABLE_UNICODE_FONT, "Enable unicode font")
I(OPT_CONSOLE_ENABLE_UNICODE_FONT_MARK, "For improved non-latin language support. Will somewhat increase memory usage.")

I(OPT_VIS, "Visual Effects")
I(OPT_VIS_GAMMA, "Gamma")
I(OPT_VIS_EXPOSURE, "Exposure")
I(OPT_VIS_BRIGHTNESS, "Brightness")
I(OPT_VIS_CONTRAST, "Contrast")
I(OPT_VIS_MAX_SCALE, "Max Scale")
I(OPT_VIS_MAX_RENDER_SCALE, "Max Render Scale")
I(OPT_VIS_ACTIVE_CAMERA, "Active Camera")
I(OPT_VIS_VSYNC, "VSync")
I(OPT_VIS_BORDERLESS_FULLSCREEN, "Borderless Fullscreen")
I(OPT_VIS_EFFECTS, "Effects")
I(OPT_VIS_ANIM_INTERP, "Animation Interpolation")
I(OPT_VIS_COLOR_CORRECTION, "Color Correction")
I(OPT_VIS_COLOR_MODIFIER, "Color Modifier")
I(OPT_VIS_LIGHTING, "Lighting")
I(OPT_VIS_SHOCKWAVES, "Shockwaves")
I(OPT_VIS_CAUSTICS, "Caustics")
I(OPT_VIS_PIXELATION, "Pixelation")
I(OPT_VIS_PIXELATION_MARK, "e.g. Retro vision pill")
I(OPT_VIS_BLOOM, "Bloom")
I(OPT_VIS_ENABLE_WATER_SURFACE_RENDERING, "Enable Water Surface rendering")
I(OPT_VIS_ENABLE_WATER_SURFACE_RENDERING_MARK, "Needs to be set when changing Water Surface setting")
I(OPT_VIS_WATER_SURFACE, "Water Surface")

I(OPT_ACC, "Accessibility")
I(OPT_ACC_AIM_LOCK, "Aim Lock")
I(OPT_ACC_RUMBLE, "Rumble")
I(OPT_ACC_MOUSE_CONTROL, "Mouse Control")
I(OPT_ACC_BULLET_VISIBILITY, "Bullet Visibility")
I(OPT_ACC_TOUCH_MODE, "Touch Mode")

I(OPT_MISC, "Misc")
I(OPT_MISC_ENABLE_MODS, "Enable Mods")
I(OPT_MISC_ENABLE_CTRL_HOTPLUG,"Enable Control Hotplug")
I(OPT_MISC_USE_STEAM_CLOUD, "Use Steam Cloud")
I(OPT_MISC_PAUSE_ON_FOCUS_LOST, "Pause on focus lost")

I(OPT_REPENTOGON, "REPENTOGON")
I(OPT_REPENTOGON_BETTER_VOID_GEN, "Better Void Generation")
I(OPT_REPENTOGON_BETTER_VOID_GEN_MARK, "The Void now pulls rooms from all unlocked floors, including alt path.")
I(OPT_REPENTOGON_HUSH_PANIC_FIX, "Hush Panic State Fix")
I(OPT_REPENTOGON_HUSH_PANIC_FIX_MARK, "Fixes the vanilla bug that causes Hush to no longer have any pause between attacks below 50% health.")
I(OPT_REPENTOGON_KEY_MASTERS_AFFECTDEAL_CHANCES, "Key Masters affect deal chances")
I(OPT_REPENTOGON_KEY_MASTERS_AFFECTDEAL_CHANCES_MARK, "Killing Key Masters will raise the chance to spawn a deal, now consistent with killing other bums.")
I(OPT_REPENTOGON_QUICKER_ROOM_CLEAR, "Quicker Room Clear")
I(OPT_REPENTOGON_QUICKER_ROOM_CLEAR_MARK, "Rooms will open their doors and spawn rewards quicker. Bosses still require their death animation to play out.")
I(OPT_REPENTOGON_PREVENT_MOD_UPDATES, "Prevent mod updates")
I(OPT_REPENTOGON_PREVENT_MOD_UPDATES_MARK, "The game will skip updating your mods folder to match your current workshop folder. Useful for temporarily emptying your mods folder during mod development.")


I(OPT_EXTRA_HUD_MODES_OFF, "Off")
I(OPT_EXTRA_HUD_MODES_NORMAL, "Normal")
I(OPT_EXTRA_HUD_MODES_MINI, "Mini")

I(OPT_ANNOUNCER_MODES_RANDOM, "Random")
I(OPT_ANNOUNCER_MODES_OFF, "Off")
I(OPT_ANNOUNCER_MODES_ALWAYS_ON, "Always on")

I(OPT_CONSOLE_FOND_MODES_DEFAULT, "Default")
I(OPT_CONSOLE_FOND_MODES_SMALL, "Small")
I(OPT_CONSOLE_FOND_MODES_TINY, "Tiny")

I(OPT_OFF_ON_MODES_OFF, "Off")
I(OPT_OFF_ON_MODES_ON, "On")

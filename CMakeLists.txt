cmake_minimum_required(VERSION 3.4.1)

string(TOLOWER ${CMAKE_BUILD_TYPE} ANDROID_BUILD_DIR)
set(DISTRIBUTION_DIR ${CMAKE_SOURCE_DIR}/android/distribution/android/SDL2/intermediates/ndkBuild)

add_definitions(
    -D_DEBUG
    -DMINIWIN
    # Skip fades and other fluff
    -DFASTER

)


include_directories(. Stub)




set(SOURCE_FILES  
      Source/automap.cpp
    Source/codec.cpp
    Source/control.cpp
    Source/cursor.cpp
    Source/dead.cpp
    Source/debug.cpp
    Source/doom.cpp
    Source/drlg_l1.cpp
    Source/drlg_l2.cpp
    Source/drlg_l3.cpp
    Source/drlg_l4.cpp
    Source/encrypt.cpp
    Source/engine.cpp
    Source/error.cpp
    Source/gendung.cpp
    Source/gmenu.cpp
    Source/help.cpp
    Source/itemdat.cpp
    Source/misdat.cpp
    Source/monstdat.cpp
    Source/spelldat.cpp
    Source/interfac.cpp
    Source/inv.cpp
    Source/items.cpp
    Source/lighting.cpp
    Source/loadsave.cpp
    Source/mainmenu.cpp
    Source/minitext.cpp
    Source/missiles.cpp
    Source/monster.cpp
    Source/mpqapi.cpp
    Source/msgcmd.cpp
    Source/msg.cpp
    Source/multi.cpp
    Source/objdat.cpp
    Source/objects.cpp
    Source/pack.cpp
    Source/palette.cpp
    Source/path.cpp
    Source/pfile.cpp
    Source/player.cpp
    Source/plrmsg.cpp
    Source/portal.cpp
    Source/quests.cpp
    Source/render.cpp
    Source/scrollrt.cpp
    Source/setmaps.cpp
    Source/sha.cpp
    Source/spells.cpp
    Source/stores.cpp
    Source/sync.cpp
    Source/textdat.cpp
    Source/themes.cpp
    Source/tmsg.cpp
    Source/town.cpp
    Source/towners.cpp
    Source/track.cpp
    Source/trigs.cpp
    Stub/wave.cpp

    3rdParty/PKWare/explode.cpp
    3rdParty/PKWare/implode.cpp

    Stub/main.cpp
    Stub/miniwin.cpp
    Stub/miniwin_rand.cpp
    Stub/appfat.cpp
    Stub/capture.cpp
    Stub/dthread.cpp
    Stub/dx.cpp
    Stub/fault.cpp
    Stub/init.cpp
    Stub/movie.cpp
    Stub/nthread.cpp
    Stub/restrict.cpp
    Stub/sound.cpp
    Stub/storm.cpp
    Stub/diabloui.cpp
    Stub/miniwin_io.cpp
    Stub/miniwin_msg_sdl.cpp
    Stub/storm_net.cpp
    Stub/validate.cpp
    Stub/effects.cpp
    Stub/sdlrender.cpp
    Stub/diablo.cpp
    Stub/gamemenu.cpp

    3rdParty/StormLib/src/FileStream.cpp
    3rdParty/StormLib/src/SBaseCommon.cpp
    3rdParty/StormLib/src/SBaseFileTable.cpp
    3rdParty/StormLib/src/SBaseSubTypes.cpp
    3rdParty/StormLib/src/SCompression.cpp
    3rdParty/StormLib/src/SFileExtractFile.cpp
    3rdParty/StormLib/src/SFileFindFile.cpp
    3rdParty/StormLib/src/SFileGetFileInfo.cpp
    3rdParty/StormLib/src/SFileOpenArchive.cpp
    3rdParty/StormLib/src/SFileOpenFileEx.cpp
    3rdParty/StormLib/src/SFileReadFile.cpp
)

PROJECT(main C CXX)

set(SDL_LOCATION ${CMAKE_SOURCE_DIR}/external/SDL2)

add_library( SDL2 SHARED IMPORTED )
add_library( SDL2_image SHARED IMPORTED )
add_library( SDL2_mixer SHARED IMPORTED )
set_target_properties(SDL2 PROPERTIES IMPORTED_LOCATION
${DISTRIBUTION_DIR}/${ANDROID_BUILD_DIR}/obj/local/${ANDROID_ABI}/libSDL2.so)
set_target_properties(SDL2_image PROPERTIES IMPORTED_LOCATION
${DISTRIBUTION_DIR}/${ANDROID_BUILD_DIR}/obj/local/${ANDROID_ABI}/libSDL2_image.so)
set_target_properties(SDL2_mixer PROPERTIES IMPORTED_LOCATION
${DISTRIBUTION_DIR}/${ANDROID_BUILD_DIR}/obj/local/${ANDROID_ABI}/libSDL2_mixer.so)


include_directories(${SDL_LOCATION}/SDL2/include)
include_directories(${SDL_LOCATION}/SDL2_image)
include_directories(${SDL_LOCATION}/SDL2_mixer)

add_library( main SHARED ${SDL_LOCATION}/SDL2/src/main/android/SDL_android_main.c ${SOURCE_FILES} )

target_link_libraries( main SDL2 SDL2_image SDL2_mixer )

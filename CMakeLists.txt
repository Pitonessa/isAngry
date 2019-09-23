cmake_minimum_required(VERSION 3.12)
project(isAngry)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(test)

include_directories(sfml/include)

link_directories(./sfml/lib)
link_libraries(libsfml-audio.2.5.1.dylib
        libsfml-audio.2.5.dylib
        libsfml-audio.dylib
        libsfml-graphics.2.5.1.dylib
        libsfml-graphics.2.5.dylib
        libsfml-graphics.dylib
        libsfml-network.2.5.1.dylib
        libsfml-network.2.5.dylib
        libsfml-network.dylib
        libsfml-system.2.5.1.dylib
        libsfml-system.2.5.dylib
        libsfml-system.dylib
        libsfml-window.2.5.1.dylib
        libsfml-window.2.5.dylib
        libsfml-window.dylib)

SET(SOURCE_FILES
        GUI/Menu/Menu.cpp
        GameObjects/Star/Star.cpp
        GameCharacter/GameCharacter.cpp
        GameCharacter/Hero/Hero.cpp
        GameObjects/Bullet/Bullet.cpp
        GUI/GameEngine.cpp
        GameCharacter/Archer/Archer.cpp
        GameCharacter/Watcher/Watcher.cpp
        GameCharacter/Brawler/Brawler.cpp
        GameObjects/GameObject.cpp
        GameCharacter/Factories/GameFactory.cpp GameCharacter/Factories/GameFactory.h)

add_library(isAngryTest ${SOURCE_FILES})
add_executable(isAngry ${SOURCE_FILES} main.cpp)


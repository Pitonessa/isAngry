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

add_library(isAngryTest GUI/Menu/Menu.cpp GameObjects/Star/Star.cpp)
add_executable(isAngry main.cpp GUI/Menu/Menu.cpp GameObjects/Star/Star.cpp GameCharacter/GameCharacter.cpp GameCharacter/GameCharacter.h GameCharacter/Hero/Hero.cpp GameCharacter/Hero/Hero.h GameObjects/Bullet/Bullet.cpp GameObjects/Bullet/Bullet.h GUI/GameEngine.cpp GUI/GameEngine.h GameCharacter/Archer/Archer.cpp GameCharacter/Archer/Archer.h GameCharacter/Watcher/Watcher.cpp GameCharacter/Watcher/Watcher.h GameCharacter/Brawler/Brawler.cpp GameCharacter/Brawler/Brawler.h)


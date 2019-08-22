cmake_minimum_required(VERSION 3.12)
project(isAngry)

set(CMAKE_CXX_STANDARD 14)

include_directories(GUI/)
link_directories(lib/)
link_libraries(libsfml-audio-d.2.5.1.dylib
        libsfml-audio-d.2.5.dylib
        libsfml-audio-d.dylib
        libsfml-graphics-d.2.5.1.dylib
        libsfml-graphics-d.2.5.dylib
        libsfml-graphics-d.dylib
        libsfml-network-d.2.5.1.dylib
        libsfml-network-d.2.5.dylib
        libsfml-network-d.dylib
        libsfml-system-d.2.5.1.dylib
        libsfml-system-d.2.5.dylib
        libsfml-system-d.dylib
        libsfml-window-d.2.5.1.dylib
        libsfml-window-d.2.5.dylib
        libsfml-window-d.dylib)

add_executable(isAngry main.cpp GUI/Menu/Menu.cpp GUI/Menu/Menu.h GameObjects/Props/Star/Star.cpp GameObjects/Props/Star/Star.h)
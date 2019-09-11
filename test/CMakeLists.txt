link_directories(lib)
link_libraries(libgtest.a)

link_directories(../cmake-build-debug)
link_libraries(libisAngryTest.a)

link_directories(../sfml/lib)
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

include_directories(include)
include_directories(../)
include_directories(../sfml/include)

add_executable(test main.cpp GameObject/_Star.cpp _Menu.cpp)
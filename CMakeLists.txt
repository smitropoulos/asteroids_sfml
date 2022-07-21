cmake_minimum_required(VERSION 3.22)
project(sfml_asteroids)

set(CMAKE_CXX_STANDARD 20)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

#Add google test
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(include)
include_directories(external/mINI/src)

add_executable(sfml_asteroids
               src/main.cpp
               src/Game.cpp
               src/EventHandler.cpp
               src/RenderableEntity.cpp
               src/Player.cpp
               src/EntitiesRepository.cpp
               src/TextureLoader.cpp
               src/TextureRepository.cpp
               src/EntitiesFactory.cpp
               src/Rock.cpp
               src/PlayerEventHandler.cpp
               include/MovementType.h include/RockEventHandler.h)
target_link_libraries(sfml_asteroids sfml-system sfml-window sfml-graphics sfml-audio ConfigurationLib)

add_subdirectory(tests)
add_subdirectory(include/configuration)

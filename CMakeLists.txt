cmake_minimum_required(VERSION 3.16)

project(MusicPlayer)

set(CMAKE_CXX_STANDARD 17)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

add_executable(MusicPlayer src/main.cpp)
target_sources(MusicPlayer PRIVATE src/common/MusicPlayer.cpp src/common/MusicPlayer.hpp)
target_link_libraries(MusicPlayer sfml-audio sfml-system)
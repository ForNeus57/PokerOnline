cmake_minimum_required(VERSION 3.24)

project(Poker_Online VERSION 0.0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULES
		${PROJECT_SOURCE_DIR}/Client
		${PROJECT_SOURCE_DIR}/Common
		${PROJECT_SOURCE_DIR}/Model
		${PROJECT_SOURCE_DIR}/Server
		)

set(COMPILER_FLAGS
		-g
		-std=c++20
		-Wall
		-Wextra
		-Wcast-align
		-Wshadow
		-Wpointer-arith
		-pedantic
		-Wconversion
		-O3
		-pipe
		)

add_subdirectory(${PROJECT_SOURCE_DIR}/Client)
add_subdirectory(${PROJECT_SOURCE_DIR}/Common)
add_subdirectory(${PROJECT_SOURCE_DIR}/Model)
add_subdirectory(${PROJECT_SOURCE_DIR}/Server)

set(Boost_INCLUDE_DIR "C:/Program Files/SDK/MinGW_Boost/include")
set(Boost_LIBRARY_DIR "C:/Program Files/SDK/MinGW_Boost/lib")
find_package(Boost 1.77.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

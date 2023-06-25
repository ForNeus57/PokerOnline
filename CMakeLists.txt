cmake_minimum_required(VERSION 3.24)

project(PokerOnline VERSION 0.0.0.6 LANGUAGES CXX)

#include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULES_DIR
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
		-Werror
		-Wcast-align
		-Wshadow
		-Wold-style-cast
		-Wpointer-arith
		-pedantic
		-Wconversion
		-O3
		-pipe
		)

set(TEST_LIBRARY_NAME
		Testing_lib
		)

string(TIMESTAMP BUILD_DATE "%Y/%m/%d")
string(TIMESTAMP BUILD_TIME "%H:%M:%S")

add_subdirectory(${PROJECT_SOURCE_DIR}/Client)
add_subdirectory(${PROJECT_SOURCE_DIR}/Common)
add_subdirectory(${PROJECT_SOURCE_DIR}/Model)
add_subdirectory(${PROJECT_SOURCE_DIR}/Server)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
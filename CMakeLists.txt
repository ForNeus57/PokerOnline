cmake_minimum_required(VERSION 3.24)

project(PokerOnline VERSION 0.0.0.7 LANGUAGES CXX)

#include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MODULES_DIR
		${PROJECT_SOURCE_DIR}/client
		${PROJECT_SOURCE_DIR}/common
		${PROJECT_SOURCE_DIR}/model
		${PROJECT_SOURCE_DIR}/server
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
		testing_lib
		)

string(TIMESTAMP BUILD_DATE "%Y/%m/%d")
string(TIMESTAMP BUILD_TIME "%H:%M:%S")

add_subdirectory(${PROJECT_SOURCE_DIR}/client)
add_subdirectory(${PROJECT_SOURCE_DIR}/common)
add_subdirectory(${PROJECT_SOURCE_DIR}/model)
add_subdirectory(${PROJECT_SOURCE_DIR}/server)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

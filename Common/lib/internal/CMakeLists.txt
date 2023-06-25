set(INCLUDE_DIR
		include
		)

set(SOURCE_DIR
		src
		)

set(LIBRARY_SOURCE
		${SOURCE_DIR}/Common/automata.cpp
		${SOURCE_DIR}/Common/poker_exception.cpp
		)

set(TEST_LIBRARY_SOURCE
		${SOURCE_DIR}/Testing/file_generator.cpp
		${SOURCE_DIR}/Testing/data_generator.cpp
		)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIBRARY_SOURCE})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${TEST_LIBRARY_SOURCE})

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})
add_library(${TEST_LIBRARY_NAME} STATIC ${TEST_LIBRARY_SOURCE})

find_package(Boost 1.74.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
	target_include_directories(${LIBRARY_NAME} SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
	target_link_libraries(${LIBRARY_NAME} PUBLIC ${Boost_LIBRARIES} ws2_32)
endif()

target_include_directories(${TEST_LIBRARY_NAME} PUBLIC ${INCLUDE_DIR}/Testing)
target_include_directories(${TEST_LIBRARY_NAME} SYSTEM PUBLIC ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(${TEST_LIBRARY_NAME} PUBLIC ${LIBRARY_NAME} gmock gmock_main gtest gtest_main)

target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR}/Common)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CONFIG_FILE_PATH})

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})


find_package(Doxygen)

if (DOXYGEN_FOUND)
	# set input and output files
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../../docs/Doxygen/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/../../docs/Doxygen/Doxyfile.out)

	# request to configure the file
	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	message("Doxygen build started")

	# Note: do not put "ALL" - this builds docs together with application EVERY TIME!
	add_custom_target( ${MODULE_NAME}Docs
			COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
			COMMENT "Generating API documentation with Doxygen"
			VERBATIM )
else (DOXYGEN_FOUND)
	message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

set(TEST_MAIN
		main_test.cpp
		)

set(TEST_SOURCE
		src/database_manager_test.cpp
		)

set(TEST_EXECUTABLE_RUN_NAME
		${MODULE_NAME}_run_tests
		)

include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${TEST_EXECUTABLE_RUN_NAME} ${TEST_MAIN} ${TEST_SOURCE})

if(Boost_FOUND)
	target_include_directories(${TEST_EXECUTABLE_RUN_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
	target_link_libraries(${TEST_EXECUTABLE_RUN_NAME} PUBLIC ${Boost_LIBRARIES} ws2_32)
endif()

target_link_libraries(${TEST_EXECUTABLE_RUN_NAME} ${LIBRARY_NAME} gmock gmock_main gtest gtest_main)

target_compile_options(${TEST_EXECUTABLE_RUN_NAME} PRIVATE ${COMPILE_OPTIONS})

add_test(NAME ${MODULE_NAME}_tests COMMAND ${TEST_EXECUTABLE_RUN_NAME})
set(TEST_MAIN
		main_test.cpp
		)

set(TEST_SOURCE
		src/card_test.cpp
		src/suit_test.cpp)

set(TEST_EXECUTABLE_RUN_NAME
		${MODULE_NAME}_run_tests
		)

include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${TEST_EXECUTABLE_RUN_NAME} ${TEST_MAIN} ${TEST_SOURCE})

target_link_libraries(${TEST_EXECUTABLE_RUN_NAME} ${LIBRARY_NAME} gmock gmock_main gtest gtest_main)

target_compile_options(${TEST_EXECUTABLE_RUN_NAME} PRIVATE ${COMPILE_OPTIONS})

add_test(NAME ${MODULE_NAME}_tests COMMAND ${TEST_EXECUTABLE_RUN_NAME})
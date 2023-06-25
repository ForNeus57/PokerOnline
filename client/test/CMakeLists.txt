set(TEST_MAIN
		main_test.cpp
		)

set(TEST_SOURCE
		src/client_test.cpp
		)

set(TEST_EXECUTABLE_RUN_NAME
		${MODULE_NAME}_run_tests
		)

add_executable(${TEST_EXECUTABLE_RUN_NAME} ${TEST_MAIN} ${TEST_SOURCE})

target_link_libraries(${TEST_EXECUTABLE_RUN_NAME} ${LIBRARY_NAME} ${TEST_LIBRARY_NAME})

target_compile_options(${TEST_EXECUTABLE_RUN_NAME} PRIVATE ${COMPILE_OPTIONS})

add_test(NAME ${MODULE_NAME}_tests COMMAND ${TEST_EXECUTABLE_RUN_NAME})
project(CommonModule VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(INPUT_CONFIG_FILE_PATH
		${PROJECT_SOURCE_DIR}/conf/Config.h.in
		)

set(CONFIG_FILE_PATH
		${PROJECT_SOURCE_DIR}/conf/Config.h
		)

configure_file(${INPUT_CONFIG_FILE_PATH} ${CONFIG_FILE_PATH})

set(MODULE_NAME
		Common
		)

set(MODULE_PATH
		${PROJECT_SOURCE_DIR}/${MODULE_NAME}
		)

set(MAIN_PATH
		main.cpp
		)

set(LIBRARY_NAME
		${MODULE_NAME}_lib
		)

add_subdirectory(lib)
add_subdirectory(test)

add_executable(${PROJECT_NAME} ${MAIN_PATH})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_NAME} ${TEST_LIBRARY_NAME})

target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILER_FLAGS})
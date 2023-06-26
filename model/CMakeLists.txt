project(model_module VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(INPUT_CONFIG_FILE_PATH
		${PROJECT_SOURCE_DIR}/conf/config.in
		)

set(CONFIG_FILE_PATH
		${PROJECT_BINARY_DIR}/conf
		)

set(CONFIG_FILE_NAME
		config.h
		)

configure_file(${INPUT_CONFIG_FILE_PATH} ${CONFIG_FILE_PATH}/${CONFIG_FILE_NAME})

set(MODULE_NAME
		model
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

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARY_NAME})

target_compile_options(${PROJECT_NAME} PRIVATE ${COMPILER_FLAGS})
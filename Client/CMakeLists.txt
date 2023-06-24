project(ClientModule VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(INPUT_CONFIG_FILE_PATH
		${PROJECT_SOURCE_DIR}/conf/Config.in
		)

set(CONFIG_FILE_PATH
		${PROJECT_SOURCE_DIR}/conf/Config.h
		)

configure_file(${INPUT_CONFIG_FILE_PATH} ${CONFIG_FILE_PATH} COPYONLY)

set(MODULE_NAME
		Client
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
set(INCLUDE_DIR
		include
		)

set(SOURCE_DIR
		src
		)

set(LIBRARY_SOURCE
		${SOURCE_DIR}/config.cpp
		${SOURCE_DIR}/program_arguments_parser.cpp
		${SOURCE_DIR}/server.cpp
		${SOURCE_DIR}/database/config.cpp
		${SOURCE_DIR}/database/config_parser.cpp
		${SOURCE_DIR}/database/controller.cpp
		${SOURCE_DIR}/database/request.cpp
		${SOURCE_DIR}/database/thread.cpp
		${SOURCE_DIR}/database/tables/users.cpp
		)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIBRARY_SOURCE})

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})

target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../external/mysql/include/jdbc)
target_include_directories(${LIBRARY_NAME} SYSTEM PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../external/mysql/include/jdbc)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../external/mysql/lib64/vs14/mysqlcppconn8-static.lib)

target_link_libraries(${LIBRARY_NAME} PRIVATE model_lib)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CONFIG_FILE_PATH})

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})

find_package(Doxygen)

if (DOXYGEN_FOUND)
	# set input and output files
	set(DOXYGEN_IN ${PROJECT_SOURCE_DIR}/docs/doxygen/Doxyfile.in)
	set(DOXYGEN_OUT ${PROJECT_BINARY_DIR}/docs/doxygen/Doxyfile.out)

	# request to configure the file
	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
	message("Doxygen build started")

	# Note: do not put "ALL" - this builds docs together with application EVERY TIME!
	add_custom_target( ${MODULE_NAME}_docs
			COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
			WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
			COMMENT "Generating API documentation with Doxygen"
			VERBATIM )
else (DOXYGEN_FOUND)
	message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

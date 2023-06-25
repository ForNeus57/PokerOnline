set(INCLUDE_DIR
		include
		)

set(SOURCE_DIR
		src
		)

set(LIBRARY_SOURCE
		${SOURCE_DIR}/card.cpp
		${SOURCE_DIR}/suit.cpp
		${SOURCE_DIR}/rank.cpp)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${LIBRARY_SOURCE})

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})

target_include_directories(${LIBRARY_NAME} PUBLIC ${INCLUDE_DIR})

target_link_libraries(${LIBRARY_NAME} PUBLIC common_lib)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CONFIG_FILE_PATH})

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})

find_package(Doxygen)

if (DOXYGEN_FOUND)
	# set input and output files
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../../docs/doxygen/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/../../docs/doxygen/Doxyfile.out)

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


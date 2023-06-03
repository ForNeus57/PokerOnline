set(LIBRARY_SOURCE
		src/automata.cpp
		)

include_directories(include)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})

find_package(Boost 1.74.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
	target_include_directories(${LIBRARY_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
	target_link_libraries(${LIBRARY_NAME} PUBLIC ${Boost_LIBRARIES} ws2_32)
endif()

target_include_directories(${LIBRARY_NAME} PUBLIC include)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CONFIG_FILE_PATH})

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})

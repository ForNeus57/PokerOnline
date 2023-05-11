set(LIBRARY_SOURCE
		src/automata.cpp
		)

include_directories(include)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})

target_include_directories(${LIBRARY_NAME} PUBLIC include)

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})

set(LIBRARY_SOURCE
		src/card.cpp
		src/suit.cpp
		src/rank.cpp)

include_directories(include)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})

target_include_directories(${LIBRARY_NAME} PUBLIC include)

target_link_libraries(${LIBRARY_NAME} PRIVATE Common_lib)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CONFIG_FILE_PATH})

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})

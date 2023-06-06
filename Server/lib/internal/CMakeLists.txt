set(LIBRARY_SOURCE
		src/database_manager.cpp
		src/server.cpp
		)

include_directories(include)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})

find_package(PostgreSQL 15.1 REQUIRED)

target_include_directories(${LIBRARY_NAME} PUBLIC include ${PostgreSQL_INCLUDE_DIRS})

target_link_libraries(${LIBRARY_NAME} PRIVATE Common_lib Model_lib PostgreSQL::PostgreSQL)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CONFIG_FILE_PATH})

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})

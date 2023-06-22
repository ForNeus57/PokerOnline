set(LIBRARY_SOURCE
		src/database_manager.cpp
		src/server.cpp
		src/database_config_parser.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCE})

target_include_directories(${LIBRARY_NAME} PUBLIC include C:/Users/domin/CLionProjects/PokerOnline/Server/lib/external/mysql/include/jdbc)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../external/mysql/lib64/vs14/mysqlcppconn8-static.lib)

target_link_libraries(${LIBRARY_NAME} PRIVATE Common_lib Model_lib)
target_include_directories(${LIBRARY_NAME} PRIVATE ${CONFIG_FILE_PATH})

target_compile_options(${LIBRARY_NAME} PRIVATE ${COMPILE_OPTIONS})

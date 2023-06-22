//
// Created by Dominik on 10.05.2023.
//

#ifndef POKER_ONLINE_DATABASE_MANAGER_H
#define POKER_ONLINE_DATABASE_MANAGER_H


#include "../../../../external/mysql/include/jdbc/cppconn/driver.h"
#include "../../../../external/mysql/include/jdbc/cppconn/exception.h"
#include "../../../../external/mysql/include/jdbc/cppconn/prepared_statement.h"

/**
 * @brief
 */
class DatabaseManager {
	private:
		sql::mysql::MySQL_Driver *driver;
		sql::Connection *connection;
	public:
		DatabaseManager();
};

#endif	//	POKER_ONLINE_DATABASE_MANAGER_H

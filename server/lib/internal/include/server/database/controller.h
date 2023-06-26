//
// Created by Dominik on 10.05.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_DATABASE_CONTROLLER_H
#define POKER_ONLINE_SERVER_SERVER_DATABASE_CONTROLLER_H


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


namespace poker::server::database {

	/**
	 * @brief
	 */
	class Controller final {
	private:
		sql::mysql::MySQL_Driver* driver;
		std::unique_ptr<sql::Connection> connection;

	public:
		Controller();

	public:


	};

}	//	namespace poker::server::database




#endif	//	POKER_ONLINE_SERVER_SERVER_DATABASE_CONTROLLER_H

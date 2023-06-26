//
// Created by Dominik on 26.06.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_DATABASE_REQUEST_H
#define POKER_ONLINE_SERVER_SERVER_DATABASE_REQUEST_H


#include <vector>
#include <any>

#include <boost/uuid/uuid.hpp>

#include <server/database/controller.h>

namespace poker::server::database {

	class Request {
	private:
		boost::uuids::uuid signature;
		void (Controller::*action)(std::vector<std::any>);
		std::vector<std::any> data;

	};

}


#endif //POKER_ONLINE_SERVER_SERVER_DATABASE_REQUEST_H

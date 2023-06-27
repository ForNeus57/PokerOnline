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

	public:
		Request() = default;
		~Request() = default;
		Request(const Request&) = default;
		Request(Request&&) = default;

	public:
		Request& operator=(const Request& other) = default;
		Request& operator=(Request&& other) noexcept = default;
	};

}


#endif //POKER_ONLINE_SERVER_SERVER_DATABASE_REQUEST_H

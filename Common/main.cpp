//
// Created by Dominik on 10.05.2023.
//
//
#ifdef _WIN32
	#define _WIN32_WINNT 0x0A00
#endif

#include <iostream>
//#include <Testing/file_generator.h>
#include <vector>

#include <boost/asio.hpp>
#include <boost/asio/ts/buffer.hpp>
#include <boost/asio/ts/internet.hpp>

int main() {

	boost::system::error_code ec;
	boost::asio::io_context context;

	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("93.184.216.34", ec), 80);

	boost::asio::ip::tcp::socket socket(context);

	socket.connect(endpoint, ec);

	if (!ec) {
		std::cout << "Works" << std::endl;
	} else {
		std::cout << ec.message() << std::endl;
	}

	if (socket.is_open()) {

	}

	return EXIT_SUCCESS;
}
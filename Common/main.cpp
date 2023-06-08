//
// Created by Dominik on 10.05.2023.
//
//
#ifdef _WIN32
	#define _WIN32_WINNT 0x0A00
#endif

#include <iostream>

#include <Testing/data_generator.h>

//#include <vector>

//#include <boost/asio.hpp>
//#include <boost/asio/ts/buffer.hpp>
//#include <boost/asio/ts/internet.hpp>

int main() {
	
	
	
	
	
	
	//for(const auto& val : poker::read_test_data<std::size_t>("Model/test/data/input_values_std_size_t_" + std::to_string(i) + ".bin")) {
	//	std::cout << val << ", ";
	//}
	//std::cout << '\n';
	
	
	
	//boost::system::error_code ec;
	
	//boost::asio::io_context context;
	
	//boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::make_address("93.184.216.34", ec), 80);
	
	//boost::asio::ip::tcp::socket socket(context);
	
	//socket.connect(endpoint, ec);
	
	//if (!ec) {
	//	std::cout << "Connected!" << std::endl;
	//} else {
	//	std::cout << "Failed to connect to address:\n" << ec.message() << std::endl;
	//}
	
	//if(socket.is_open()) {
	//	std::string sRequest =
	//			"GET /index.html HTTP/1:1\r\n"
	//			"Host: example.com\r\n"
	//			"Connection: close\r\n\r\n";
	//
	//	socket.write_some(boost::asio::buffer(sRequest.data(), sRequest.size()), ec);
	//
	//
	//
	//	size_t bytes =socket.available();
	//	std::cout << "Bytes available: " << bytes << std::endl;
		
	//	if (bytes > 0) {
	//		std::vector<char> vBuffer(bytes);
	//		socket.read_some(boost::asio::buffer(vBuffer.data(), vBuffer.size()), ec);
	//
	//		for (auto c : vBuffer) {
	//			std::cout << c;
	//		}
	//	}
	//} else {
	//	std::cout << "Socket is closed." << std::endl;
	//}
	
	
	
	return EXIT_SUCCESS;
}
//
// Created by Dominik on 22.06.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_DATABASE_CONFIG_PARSER_H
#define POKER_ONLINE_SERVER_SERVER_DATABASE_CONFIG_PARSER_H

#include <filesystem>
#include <tuple>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace poker::server::database {

	/**
	 * @brief
	 */
	class DatabaseConfigParser {
	public:
		const static std::string server_key;
		const static std::string port_key;
		const static std::string username_key;
		const static std::string password_key;
		const static std::string databases_key;

	private:
		std::filesystem::path config_file_path;
		boost::property_tree::ptree pt;

	public:
		DatabaseConfigParser(const std::filesystem::path& input_path);

	public:
		std::tuple<std::string, std::string, std::string, std::string, std::vector<std::string>> parse();

	};

}	//	namespace poker::server::database



#endif  //  POKER_ONLINE_SERVER_SERVER_DATABASE_CONFIG_PARSER_H

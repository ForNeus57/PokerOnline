//
// Created by Dominik on 27.06.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_CONFIG_H
#define POKER_ONLINE_SERVER_SERVER_CONFIG_H


#include "server/program_arguments_parser.h"

#include <filesystem>

namespace poker::server {

	class Config final {
	private:
		std::filesystem::path path_to_database_connection_details;
		const ProgramArgumentsParser &parser;

	public:
		Config();

	public:
		static void setParser(const ProgramArgumentsParser&);

	};

}	//	namespace poker::server


#endif	//	POKER_ONLINE_SERVER_SERVER_CONFIG_H

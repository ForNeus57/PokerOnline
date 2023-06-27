//
// Created by Dominik on 28.06.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_PROGRAM_ARGUMENTS_PARSER_H
#define POKER_ONLINE_SERVER_SERVER_PROGRAM_ARGUMENTS_PARSER_H


#include <vector>
#include <string_view>

namespace poker::server {

	class ProgramArgumentsParser final {
	private:
		std::vector<std::string_view> data;

	public:
		ProgramArgumentsParser(int argc, char**argv);
		~ProgramArgumentsParser();

	public:


	private:
		void parse();

	};

}	//	namespace poker::server




#endif	//	POKER_ONLINE_SERVER_SERVER_PROGRAM_ARGUMENTS_PARSER_H

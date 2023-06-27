//
// Created by Dominik on 10.05.2023.
//

#include <server/database/thread.h>
#include <server/config.h>
#include <server/program_arguments_parser.h>

#include <iostream>

int main(int argc, char** argv) {

	poker::server::ProgramArgumentsParser parser(argc, argv);

	poker::server::Config::setParser(parser);


	std::shared_ptr<bool> stillRun = std::make_shared<bool>(true);

	return EXIT_SUCCESS;
}
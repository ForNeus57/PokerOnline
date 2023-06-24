//
// Created by Dominik on 22.06.2023.
//
#include "Server/Database/database_config_parser.h"


//  Static class attributes:

const std::string DatabaseConfigParser::server_key = "server";
const std::string DatabaseConfigParser::port_key = "port";
const std::string DatabaseConfigParser::username_key = "username";
const std::string DatabaseConfigParser::password_key = "password";
const std::string DatabaseConfigParser::databases_key = "databases";

//  Method definitions:

DatabaseConfigParser::DatabaseConfigParser(const std::filesystem::path& input_path) {
    boost::property_tree::json_parser::read_json(this->config_file_path.string(), this->pt);
}
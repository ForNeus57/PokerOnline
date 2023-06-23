//
// Created by Dominik on 22.06.2023.
//

#ifndef POKER_ONLINE_DATABASE_CONFIG_PARSER_H
#define POKER_ONLINE_DATABASE_CONFIG_PARSER_H

#include <filesystem>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class DatabaseConfigParser {
public:
    const static std::string server_key;
    const static std::string username_key;
    const static std::string password_key;
    const static std::string schema_key;
private:
    std::filesystem::path config_file_path;
    boost::property_tree::ptree pt;

    DatabaseConfigParser(const std::filesystem::path& input_path);



};

#endif  //  POKER_ONLINE_DATABASE_CONFIG_PARSER_H

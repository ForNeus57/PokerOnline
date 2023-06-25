//
// Created by Dominik on 22.06.2023.
//

#ifndef POKER_ONLINE_DATABASE_CONFIG_H
#define POKER_ONLINE_DATABASE_CONFIG_H

#include <memory>
#include <vector>
#include <filesystem>

class DatabaseConfig {
private:
	std::filesystem::path connectionDetailsLocation;
protected:
	static std::shared_ptr<DatabaseConfig> instance;
	std::string server;
	std::string port;
	std::string username;
	std::string password;
	std::vector<std::string> databases;

protected:
	DatabaseConfig();

public:
	DatabaseConfig(const DatabaseConfig&) = delete;

public:
	void operator=(const DatabaseConfig&) = delete;

public:
	static std::shared_ptr<DatabaseConfig> getInstance();
	void setDetailsLocation(std::filesystem::path path);
	
private:
	void parse(std::filesystem::path file);

};

#endif  //  POKER_ONLINE_DATABASE_CONFIG_H

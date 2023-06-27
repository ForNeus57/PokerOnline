//
// Created by Dominik on 22.06.2023.
//

#ifndef POKER_ONLINE_SERVER_SERVER_DATABASE_CONFIG_H
#define POKER_ONLINE_SERVER_SERVER_DATABASE_CONFIG_H


#include <memory>
#include <vector>
#include <filesystem>

namespace poker::server::database {

	/**
	 * @brief
	 *
	 * @note    This class resembles Singleton design pattern. In order to get pointer to a global config object use .getInstance() method.
	 *
	 * @note    All the attributes of this class are immutable.
	 */
	class Config final {
	private:
		std::filesystem::path connectionDetailsLocation;

	protected:
		static std::shared_ptr<Config> instance;
		std::string server;
		std::string port;
		std::string username;
		std::string password;
		std::vector<std::string> databases;

	protected:
		Config();

	public:
		Config(const Config&) = delete;

	public:
		void operator=(const Config&) = delete;

	public:
		static std::shared_ptr<Config> getInstance();
		void setDetailsLocation(std::filesystem::path path);

	private:
		void parse(std::filesystem::path file);

	};

}	//	namespace poker::server::database


#endif  //  POKER_ONLINE_SERVER_SERVER_DATABASE_CONFIG_H

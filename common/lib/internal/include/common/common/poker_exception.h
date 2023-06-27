//
// Created by Dominik on 11.06.2023.
//

#ifndef POKER_ONLINE_COMMON_COMMON_POKER_EXCEPTION_H
#define POKER_ONLINE_COMMON_COMMON_POKER_EXCEPTION_H


#include <exception>
#include <string>

namespace poker::common {


	class PokerException: public std::exception {
	private:
		std::string message;

	public:
		explicit PokerException(std::string  msg);
		virtual ~PokerException() = default;

	public:
		const char* what() const noexcept override;

	};

}	//	namespace poker::common


#endif	//	POKER_ONLINE_COMMON_COMMON_POKER_EXCEPTION_H

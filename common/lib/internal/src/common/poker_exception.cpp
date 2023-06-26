//
// Created by Dominik on 11.06.2023.
//

#include <utility>

#include "common/poker_exception.h"

namespace poker::common {

	//	Constructor definitions
	PokerException::PokerException(std::string  msg): message(std::move(msg)) {}

	//	Other definitions
	const char* PokerException::what() const noexcept {
		return this->message.c_str();
	}

}	//	namespace poker::common
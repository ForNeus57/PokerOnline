//
// Created by Dominik on 11.06.2023.
//

#ifndef POKER_ONLINE_POKER_EXCEPTION_H
#define POKER_ONLINE_POKER_EXCEPTION_H

#include <stdexcept>

namespace poker {
	
	inline namespace common {
		
		class PokerException : public std::exception {

		};
		
}	//	namespace common
}	//	namespace poker

#endif	//	POKER_ONLINE_POKER_EXCEPTION_H

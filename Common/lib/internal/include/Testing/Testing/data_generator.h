//
// Created by Dominik on 11.06.2023.
//

#ifndef POKER_ONLINE_DATA_GENERATOR_H
#define POKER_ONLINE_DATA_GENERATOR_H

#include <cstddef>

class DataGenerator {
	public:
		using SizeType = std::size_t;
		
		//	Class constants.
	public:
		constexpr static SizeType DEFAULT_NUMBER_OF_INSTANCES = 1000000;
		constexpr static SizeType NUMBER_OF_BITS_IN_A_BYTE = 8;
		constexpr static SizeType RANGE_MULTIPLIER = 2;
};

#endif //POKER_ONLINE_DATA_GENERATOR_H

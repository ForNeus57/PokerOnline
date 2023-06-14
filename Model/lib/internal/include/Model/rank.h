/**
 * @file 	rank.h
 * @author 	Dominik Breksa
 * @date 	19.05.2023
 * @brief	Header file relating to Rank class.
 * @see		rank.cpp file.
 * @version 0.5.2
**/

#ifndef POKER_ONLINE_RANK_H
#define POKER_ONLINE_RANK_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <array>


namespace poker {
	inline namespace model {
		/**
		 * @brief	Class that represents Rank of standard playing card
		 *
		 */
		class Rank {
			public:
				enum class Value : uint16_t;		//	Forward declaration of Value enum class

			public:
				using ValueUnderlingType = std::underlying_type<Value>::type;

			public:
				enum class Value : ValueUnderlingType {
					//	Actual values
					Ace		=	0b1,				//	1
					Two		=	0b10,				//	2
					Three	=	0b100,				//	4
					Four	=	0b1000,				//	8
					Five	=	0b10000,			//	16
					Six		=	0b100000,			//	32
					Seven	=	0b1000000,			//	64
					Eight	=	0b10000000,			//	128
					Nine	=	0b100000000,		//	256
					Ten		=	0b1000000000,		//	512
					Jack	=	0b10000000000,		//	1024
					Queen	=	0b100000000000,		//	2048
					King	=	0b1000000000000,	//	4096
				};

			public:
				constexpr static std::size_t VALUE_RANGE = 13;
				constexpr static std::size_t SHIFT_VALUE = 1;
				constexpr static std::size_t ADJUST_VALUE_TO_INDEX = 1;
				constexpr static std::size_t DEFAULT_CREATOR_INDEX = 0;

			private:
				Value _val;

			public:
				Rank();
				explicit Rank(ValueUnderlingType value);
				explicit Rank(Value value);
				Rank(const Rank& value) = default;
				Rank(Rank&&) noexcept = default;
				~Rank() = default;

			public:
				Rank& operator=(const Rank& other) = default;
				Rank& operator=(Rank&& other) noexcept = default;
				bool operator==(const Rank& other) const;
				bool operator!=(const Rank& other) const;
				bool operator<(const Rank& other) const;
				bool operator>(const Rank& other) const;
				bool operator<=(const Rank& other) const;
				bool operator>=(const Rank& other) const;
				std::strong_ordering operator<=>(const Rank& other) const;
				explicit operator std::string() const;

			public:
				Value getValue() const;
				ValueUnderlingType getUnderlingValue() const;

			public:
				static bool isValid(ValueUnderlingType checked_value);
				static bool isValid(std::size_t idx);
				static std::array<Rank, VALUE_RANGE> generateIterable();

			private:
		};

}	//	namespace model
}	//	namespace poker

#endif	//	POKER_ONLINE_RANK_H

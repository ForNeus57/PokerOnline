/**
 * @file 	suit.h
 * @author 	Dominik Breksa
 * @date 	12.05.2023
 * @brief	Header file relating to Suit class.
 * @see		suit.cpp file.
 * @version 0.5.2
**/

#ifndef POKER_ONLINE_SUIT_H
#define POKER_ONLINE_SUIT_H

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstddef>


namespace poker {
	inline namespace model {
		/**
		 * @brief	Class that represents Suit of standard playing card
		 *
		 */
		class Suit {
			public:
				enum class Value : uint8_t;		//	Forward declaration of Value enum class
				
			public:
				using ValueUnderlingType = std::underlying_type<Value>::type;
				
			public:
				enum class Value : uint8_t {
					//	Actual values
					Heart	=	0b1,			//	1
					Diamond	=	0b10,			//	2
					Club	=	0b100,			//	4
					Pick	=	0b1000,			//	8
				};
				
			public:
				constexpr static std::size_t VALUE_RANGE = 4;
				constexpr static std::size_t SHIFT_VALUE = 1;
				constexpr static std::size_t SHIFT_VALUE_INDEX = 1;
			
			private:
				Value _val;
				
			public:
				Suit();
				explicit Suit(ValueUnderlingType value);
				explicit Suit(Value value);
				Suit(const Suit& value) = default;
				Suit(Suit&&) noexcept = default;
				~Suit() = default;
			
			public:
				Suit& operator=(const Suit& other) = default;
				Suit& operator=(Suit&& other) noexcept = default;
				bool operator==(const Suit& other) const;
				bool operator!=(const Suit& other) const;
				bool operator<(const Suit& other) const;
				bool operator>(const Suit& other) const;
				bool operator<=(const Suit& other) const;
				bool operator>=(const Suit& other) const;
				std::strong_ordering operator<=>(const Suit& other) const;
				friend std::ostream& operator<<(std::ostream& os, const Suit& obj);
				friend std::istream& operator>>(std::istream& is, Suit& obj);
				explicit operator std::string() const;
				Suit& operator++();
				Suit operator++(int);
				Suit& operator--();
				Suit operator--(int);
				Suit operator()(std::size_t idx) const;
				
			public:
				Value getValue() const;
				ValueUnderlingType getUnderlingValue() const;
				
			public:
				static bool isValid(ValueUnderlingType);
				
			private:
		};
}	//	namespace model
}	//	namespace poker

#endif	//	POKER_ONLINE_SUIT_H

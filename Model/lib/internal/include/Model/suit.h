/**
 * @file 	suit.h
 * @author 	Dominik Breksa
 * @date 	12.05.2023
 * @brief	Header file relating to Suit class.
 * @see		token.cpp file.
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
		 * @note	This class have implemented iterator, that ...
		 */
		class Suit {
			private:
				using ValueType = uint8_t;
				
			public:
				enum class Value : ValueType {
					//	Actual values
					Heart	=	0b1,
					Diamond	=	0b10,
					Club	=	0b100,
					Pick	=	0b1000,
					FIRST	=	Heart,
					LAST	=	Pick
				};
				class Iterator {
					public:
						using iterator_category = std::bidirectional_iterator_tag;
						using difference_type = std::ptrdiff_t;        //	Furthered research needed
						using value_type = Value;
						using pointer = void;
						using reference = Value&;
						
					private:
						value_type _itter_val;
						bool _isLast;
						
					public:
						Iterator();
						explicit Iterator(value_type startValue);
						~Iterator() = default;
					
					public:
						value_type operator*() const;
						reference operator++();
						value_type operator++(int);
						reference operator--();
						value_type operator--(int);
						inline bool operator==(const reference other) const;
						inline bool operator!=(const reference other) const;
					
					private:
						//	No private methods have been defined yet.
				};
				
			public:
				constexpr static std::size_t VALUE_RANGE = 4;
				constexpr static std::size_t SHIFT_VALUE = 1;
			
			private:
				Value _val;
				
			public:
				Suit();
				explicit Suit(ValueType value);
				explicit Suit(Value value);
				Suit(const Suit& value) = default;
				Suit(Suit&&) noexcept = default;
				~Suit() = default;
			
			public:
				Suit& operator=(const Suit& other) = default;
				Suit& operator=(Suit&& other) noexcept = default;
				inline bool operator==(const Suit& other) const;
				inline bool operator!=(const Suit& other) const;
				inline bool operator<(const Suit& other) const;
				inline bool operator>(const Suit& other) const;
				inline bool operator<=(const Suit& other) const;
				inline bool operator>=(const Suit& other) const;
				auto operator<=>(const Suit& other) const;
				friend std::ostream& operator<<(std::ostream& os, const Suit& obj);
				friend std::istream& operator>>(std::istream& is, Suit& obj);
				explicit operator std::string() const;
				Suit& operator++();
				Suit operator++(int);
				Suit& operator--();
				Suit operator--(int);
				Suit operator()(std::size_t idx) const;
			
			public:
				Iterator begin() const;
				Iterator end() const;
				
			public:
				Value getValue() const;
				inline static bool isValid(ValueType);
				
			private:
				//	No private methods have been defined yet.
		};
}	//	namespace model
}	//	namespace poker

#endif	//	POKER_ONLINE_SUIT_H

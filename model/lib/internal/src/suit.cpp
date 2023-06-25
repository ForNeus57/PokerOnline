/**
 * @file 	suit.cpp
 * @author 	Dominik Breksa
 * @date 	12.05.2023
 * @brief	Source file relating to Suit class.
 * @see		suit.h file.
 * @version 0.9.0
**/

#include "model/suit.h"

namespace poker {
	inline namespace model {
		//	Static variables of the class
		
		//	Method definitions
		Suit::Suit() : _val(Value::Heart) {}
		
		Suit::Suit(Value value) : _val(value) {}
		
		Suit::Suit(Suit::ValueUnderlingType value) {
			if(Suit::isValid(value))
				this->_val = static_cast<Value>(value);
			else
				throw std::invalid_argument("Unknown or wrong suit value provided for constructor!");
		}
		
		bool Suit::operator==(const Suit& other) const {
			return (static_cast<Suit::ValueUnderlingType>(this->_val) & static_cast<Suit::ValueUnderlingType>(other._val)) > 0;
		}
		
		bool Suit::operator!=(const Suit& other) const {
			return !(*this == other);
		}
		
		bool Suit::operator<(const Suit& other) const {
			return this->_val < other._val;
		}
		
		bool Suit::operator>(const Suit& other) const {
			return other._val < this->_val;
		}
		
		bool Suit::operator<=(const Suit& other) const {
			return !(this->_val > other._val);
		}
		
		bool Suit::operator>=(const Suit& other) const {
			return !(this->_val < other._val);
		}
		
		std::strong_ordering Suit::operator<=>(const Suit& other) const {
			return this->_val <=> other._val;
		}
		Suit::operator std::string() const {
			switch(this->_val) {
				case Value::Heart:
					return "Suit(_val=Suit::Value::Heart)";
				case Value::Diamond:
					return "Suit(_val=Suit::Value::Diamond)";
				case Value::Club:
					return "Suit(_val=Suit::Value::Club)";
				case Value::Pick:
					return "Suit(_val=Suit::Value::Pick)";
			}
			return "Suit(ERROR)";
		}
		
		Suit::Value Suit::getValue() const {
			return this->_val;
		}
		
		Suit::ValueUnderlingType Suit::getUnderlingValue() const {
			return static_cast<Suit::ValueUnderlingType>(this->_val);
		}
		
		//	Static methods definitions
		bool Suit::isValid(ValueUnderlingType checked_value) {
			if (checked_value == static_cast<ValueUnderlingType>(Value::Heart)) return true;
			if (checked_value == static_cast<ValueUnderlingType>(Value::Diamond)) return true;
			if (checked_value == static_cast<ValueUnderlingType>(Value::Club)) return true;
			if (checked_value == static_cast<ValueUnderlingType>(Value::Pick)) return true;
			
			return false;
		}
		bool Suit::isValid(std::size_t idx) {
			return idx < Suit::VALUE_RANGE;
		}
		std::array<Suit, Suit::VALUE_RANGE> Suit::generateIterable() {
			std::array<Suit, Suit::VALUE_RANGE> output{};
			
			for (std::size_t itter = Suit::DEFAULT_CREATOR_INDEX; Suit::isValid(itter); ++itter)
				output[itter] = Suit(itter);
			
			return output;
		}
		
}	//	namespace model
}	//	namespace poker
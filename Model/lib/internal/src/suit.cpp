/**
 * @file 	suit.cpp
 * @author 	Dominik Breksa
 * @date 	12.05.2023
 * @brief	Source file relating to Suit class.
 * @see		suit.h file.
 * @version 0.7.1
**/

#include "Model/suit.h"

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
				throw std::invalid_argument("Unknown or wrong suit value provided!");
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
		
		std::ostream& operator<<(std::ostream& os, const Suit& obj) {
			return os << std::string(obj);
		}
		
		std::istream& operator>>(std::istream& is, Suit& obj) {
			Suit::ValueUnderlingType value;
			is >> value;
			if(Suit::isValid(value))
				obj = Suit(value);
			else
				is.setstate(std::ios::failbit);
			return is;
		}
		
		Suit::operator std::string() const {
			switch(this->_val) {
				case Value::Heart:
					return "Heart";
				case Value::Diamond:
					return "Diamond";
				case Value::Club:
					return "Club";
				case Value::Pick:
					return "Pick";
			}
		}
		
		Suit& Suit::operator++() {
			if(this->_val == Value::Pick) return *this;
			
			this->_val = static_cast<Value>(static_cast<Suit::ValueUnderlingType>(this->_val) << Suit::SHIFT_VALUE);
			return *this;
		}
		
		Suit Suit::operator++(int) {
			Suit old = *this;
			operator++();
			return old;
		}
		
		Suit& Suit::operator--() {
			if(this->_val == Value::Heart) {
				return *this;
			}
			this->_val = static_cast<Value>(static_cast<Suit::ValueUnderlingType>(this->_val) >> Suit::SHIFT_VALUE);
			return *this;
		}
		
		Suit Suit::operator--(int) {
			Suit old = *this;
			operator--();
			return old;
		}
		
		Suit Suit::operator()(size_t idx) const {
			if(idx > Suit::VALUE_RANGE - Suit::SHIFT_VALUE_INDEX) throw std::out_of_range("Cannot generate adequate object. Index is out of range.");
			
			return Suit(static_cast<Suit::ValueUnderlingType>(Suit::Value::Heart) << static_cast<Suit::ValueUnderlingType>(idx));
		}
		
		Suit::Value Suit::getValue() const {
			return this->_val;
		}
		
		Suit::ValueUnderlingType Suit::getUnderlingValue() const {
			return static_cast<Suit::ValueUnderlingType>(this->_val);
		}
		
		//	Static methods definitions
		bool Suit::isValid(ValueUnderlingType value_to_be_checked) {
			if (value_to_be_checked == static_cast<ValueUnderlingType>(Value::Heart)) return true;
			if (value_to_be_checked == static_cast<ValueUnderlingType>(Value::Diamond)) return true;
			if (value_to_be_checked == static_cast<ValueUnderlingType>(Value::Club)) return true;
			if (value_to_be_checked == static_cast<ValueUnderlingType>(Value::Pick)) return true;
			
			return false;
		}
		
}	//	namespace model
}	//	namespace poker
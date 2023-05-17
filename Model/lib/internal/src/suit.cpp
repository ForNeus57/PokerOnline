//
// Created by Dominik on 12.05.2023.
//
#include "Model/suit.h"

namespace poker {
	inline namespace model {
		//	Iterator definitions
		
		//	Static variables of the class
		
		//	Method definitions
		Suit::Suit() : _val(Value::FIRST) {}
		
		Suit::Suit(Suit::ValueType value) {
			if(Suit::isValid(value))
				this->_val = static_cast<Value>(value);
			else
				throw std::invalid_argument("Unknown or wrong suit value provided!");
		}
		
		Suit::Suit(Value value) : _val(value) {}
		
		inline bool Suit::operator==(const Suit& other) const {
			return (static_cast<Suit::ValueType>(this->_val) & static_cast<Suit::ValueType>(other._val)) > 0;
		}
		
		inline bool Suit::operator!=(const Suit& other) const {
			return !(*this == other);
		}
		
		inline bool Suit::operator<(const Suit& other) const {
			return this->_val < other._val;
		}
		
		inline bool Suit::operator>(const Suit& other) const {
			return other._val < this->_val;
		}
		
		inline bool Suit::operator<=(const Suit& other) const {
			return !(this->_val > other._val);
		}
		
		inline bool Suit::operator>=(const Suit& other) const {
			return !(this->_val < other._val);
		}
		
		auto Suit::operator<=>(const Suit& other) const {
			return this->_val <=> other._val;
		}
		
		std::ostream& operator<<(std::ostream& os, const Suit& obj) {
			return os << std::string(obj);
		}
		
		std::istream& operator>>(std::istream& is, Suit& obj) {
			Suit::ValueType value;
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
			if(this->_val == Value::Pick) {
				return *this;
			}
			this->_val = static_cast<Value>(static_cast<Suit::ValueType>(this->_val) << Suit::SHIFT_VALUE);
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
			this->_val = static_cast<Value>(static_cast<Suit::ValueType>(this->_val) >> Suit::SHIFT_VALUE);
			return *this;
		}
		
		Suit Suit::operator--(int) {
			Suit old = *this;
			operator--();
			return old;
		}
		
		Suit Suit::operator()(size_t idx) const {
			if(idx > Suit::VALUE_RANGE - Suit::SHIFT_VALUE)
				throw std::out_of_range("Cannot generate adequate object. Index is out of range.");
			
			return Suit(static_cast<Suit::ValueType>(Suit::Value::FIRST) << static_cast<Suit::ValueType>(idx));
		}
		
		Suit::Value Suit::getValue() const {
			return this->_val;
		}
		
		//	Static methods definitions
		bool Suit::isValid(ValueType value_to_be_checked) {
		
		}
}	//	namespace model
}	//	namespace poker
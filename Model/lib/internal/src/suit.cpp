//
// Created by Dominik on 12.05.2023.
//
#include "Model/suit.h"

namespace poker::model {
	//	Iterator definitions
	
	//	Static variables of the class
	
	//	Method definitions
	Suit::Suit(): _val(Value::Heart) {}
	Suit::Suit(unsigned char value) {
		if (Suit::isValid(value))
			this->_val = static_cast<Value>(value);
		else
			throw std::invalid_argument("Unknown or wrong suit value provided!");
	}
	Suit::Suit(Value value) {
		if (Suit::isValid(value))
			this->_val = value;
		else
			throw std::invalid_argument("Unknown or wrong suit value provided!");
	}
	inline bool Suit::operator==(const Suit& other) const {
		return (static_cast<unsigned char>(this->_val) & static_cast<unsigned char>(other._val)) > 0;
	}
	inline bool Suit::operator!=(const Suit& other) const {
		return !(*this == other);
	}
	inline bool Suit::operator<(const Suit& other) {
		return this->_val < other._val;
	}
	inline bool Suit::operator>(const Suit& other) {
		return other._val < this->_val;
	}
	inline bool Suit::operator<=(const Suit& other) {
		return !(this->_val > other._val);
	}
	inline bool Suit::operator>=(const Suit& other) {
		return !(this->_val < other._val);
	}
	auto Suit::operator<=>(const Suit& other) const {
		return this->_val <=> other._val;
	}
	std::ostream& operator<<(std::ostream& os, const Suit& obj) {
		return os << std::string(obj);
	}
	std::istream& operator>>(std::istream& is, Suit& obj) {
		unsigned char value;
		is >> value;
		if (Suit::isValid(value))
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
			default:
				throw std::invalid_argument("Unknown or wrong suit value provided!");
		}
	}
	Suit& Suit::operator++() {
		this->_val = static_cast<Value>(static_cast<unsigned char>(this->_val) << 1);
		return *this;
	}
}
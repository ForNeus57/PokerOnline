//
// Created by Dominik on 13.05.2023.
//

#ifndef POKER_ONLINE_ITERATIVE_ENUM_H
#define POKER_ONLINE_ITERATIVE_ENUM_H

#include <functional>
#include <type_traits>

/**
 * @brief
 *
 * @todo 	Think about if the Operation forward should take T as an argument instead of U
 * @todo 	Static assert the T::FIRST, T::LAST
 *
 *
 * @tparam	T					-	Enum that you want to iterate over structured like this
 * @tparam	OperationForward	-
 */
template<typename T, typename OperationForward>
class IterativeEnum {
	public:
		using U = std::underlying_type<T>;
	public:
		class Iterator {
			public:
				using	iterator_category	=	std::input_iterator_tag;
				using	difference_type  	=	std::ptrdiff_t;		//	Furthered research needed
				using	value_type       	=	T;
				using	pointer          	=	void;
				using	reference        	=	T&;
			public:
				const static int INCREMENT_VALUE = 1;
			private:
				U _iterated_value;
			public:
				explicit Iterator(value_type value):_iterated_value(static_cast<U>(value)) {}
				Iterator(const Iterator&) = default;
				Iterator(Iterator&&) noexcept = default;
				~Iterator() = default;
			public:
				value_type operator*() const {
					return static_cast<T>(this->_iterated_value);
				}
				reference operator++() {
					*this->_iterated_value = executeOperation(*this->_iterated_value, Iterator::INCREMENT_VALUE);
					return *this;
				}
				value_type operator++(int) {
					value_type old = *this;
					this->operator++();
					return old;
				}
				inline bool operator==(const reference other) const {
					return this->_iterated_value == other._iterated_value;
				}
				inline bool operator!=(const reference other) const {
					return !(this->_iterated_value == other._iterated_value);
				}
		};
	public:
		T val;
	public:
		IterativeEnum(T value) {
			//static_assert(std::is_enum<T>, "");
		}
	public:
		Iterator begin(IterativeEnum) {
			return Iterator(T::FIRST);
		}
		Iterator end(IterativeEnum) {
			return Iterator(static_cast<T>(executeOperation(static_cast<U>(T::LAST), Iterator::INCREMENT_VALUE)));
		}
	private:
		U static executeOperation(U value, int change) {
			static_assert(std::is_same_v<OperationForward, U(*)(U, int)>, "Function pointer does not match criteria. It mus resemble U(*)(U, int) this structure.");
			return OperationForward(value, change);
		}
};

#endif //POKER_ONLINE_ITERATIVE_ENUM_H

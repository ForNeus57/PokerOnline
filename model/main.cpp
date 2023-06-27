//
// Created by Dominik on 10.05.2023.
//
#include <model/suit.h>

int main() {
	poker::model::Suit s1{};
	poker::model::Suit s2(poker::model::Suit::Value::Pick);
	std::cout << (s1 < s2) << std::endl;
  
	return EXIT_SUCCESS;
}
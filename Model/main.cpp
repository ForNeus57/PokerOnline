//
// Created by Dominik on 10.05.2023.
//
#include <Model/suit.h>

int main() {
	poker::Suit s1{};
	poker::Suit s2(poker::Suit::Value::Pick);
	std::cout << (s1 < s2) << std::endl;
  
	return EXIT_SUCCESS;
}
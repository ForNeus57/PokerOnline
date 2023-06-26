//
// Created by Dominik on 10.05.2023.
//

#ifndef POKER_ONLINE_MODEL_MODEL_CARD_H
#define POKER_ONLINE_MODEL_MODEL_CARD_H


#include <model/suit.h>
#include <model/rank.h>

namespace poker::model {

	/**
	 * @brief
	 */
	class Card {
	private:
		Suit suit;
		Rank rank;

	public:
		Card();
		explicit Card(std::int8_t);
		Card(const Card& value) = default;
		Card(Card&&) noexcept = default;
		~Card() = default;

	public:
		Card& operator=(const Card& other) = default;
		Card& operator=(Card&& other) noexcept = default;
		bool operator==(const Card& other) const;
		bool operator!=(const Card& other) const;

	public:
		Suit getSuit() const;
		Rank getRank() const;

	};

}	//	namespace poker::model


#endif	//	POKER_ONLINE_MODEL_MODEL_CARD_H

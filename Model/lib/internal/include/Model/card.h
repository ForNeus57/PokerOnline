//
// Created by Dominik on 10.05.2023.
//

#ifndef POKER_ONLINE_CARD_H
#define POKER_ONLINE_CARD_H

#include <Model/suit.h>
#include <Model/rank.h>

namespace poker {
 	inline namespace model {
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
}	//	namespace model
}	//	namespace poker



#endif    //	POKER_ONLINE_CARD_H

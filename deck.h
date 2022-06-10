#ifndef DECK_H
#define DECK_H

#include <vector>
#include <stack>

#include "card.h"

class Deck {
public:
	Deck();
	~Deck();

public:
	void shuffle();
	Card* drawCard();

protected:
	std::vector<Card*> deck;
	std::stack<Card*> shuffledDeck;
};

#endif
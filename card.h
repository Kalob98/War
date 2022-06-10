#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
	Card(std::string value, std::string suit);
	~Card();

public:
	void printCard();
	void testSuits(Card card1, Card card2);
	void testValues(Card card1, Card card2);
	int compareValues(Card compare);

protected:
	std::string value;
	std::string suit;
};

#endif
#include <iostream>
#include <stdlib.h>
#include <string>
#include "card.h"

Card::Card(std::string value, std::string suit) {
	this->value = value;
	this->suit = suit;
}

Card::~Card() {

}

void Card::printCard() {
	std::cout << value << " of " << suit << std::endl;
}

void Card::testSuits(Card card1, Card card2) {
	if (card1.suit == card2.suit) {
		std::cout << card1.value << " of " << card1.suit << " and " << card2.value << " of " << card2.suit << " have the same suit" << std::endl;
	}
	else {
		std::cout << card1.value << " of " << card1.suit << " and " << card2.value << " of " << card2.suit << " do not have the same suit" << std::endl;
	}
}

void Card::testValues(Card card1, Card card2) {

	// Changing the string value of the card's value and converting it to an int to do comparisons.
	int cardValue1;
	int cardValue2;
	if (card1.value.compare("Two") == 0) {
		cardValue1 = 2;
	}
	if (card1.value.compare("Three") == 0) {
		cardValue1 = 3;
	}
	if (card1.value.compare("Four") == 0) {
		cardValue1 = 4;
	}
	if (card1.value.compare("Five") == 0) {
		cardValue1 = 5;
	}
	if (card1.value.compare("Six") == 0) {
		cardValue1 = 6;
	}
	if (card1.value.compare("Seven") == 0) {
		cardValue1 = 7;
	}
	if (card1.value.compare("Eight") == 0) {
		cardValue1 = 8;
	}
	if (card1.value.compare("Nine") == 0) {
		cardValue1 = 9;
	}
	if (card1.value.compare("Ten") == 0) {
		cardValue1 = 10;
	}
	if (card1.value.compare("Jack") == 0) {
		cardValue1 = 11;
	}
	if (card1.value.compare("Queen") == 0) {
		cardValue1 = 12;
	}
	if (card1.value.compare("King") == 0) {
		cardValue1 = 13;
	}
	if (card1.value.compare("Ace") == 0) {
		cardValue1 = 14;
	}
	if (card2.value.compare("Two") == 0) {
		cardValue2 = 2;
	}
	if (card2.value.compare("Three") == 0) {
		cardValue2 = 3;
	}
	if (card2.value.compare("Four") == 0) {
		cardValue2 = 4;
	}
	if (card2.value.compare("Five") == 0) {
		cardValue2 = 5;
	}
	if (card2.value.compare("Six") == 0) {
		cardValue2 = 6;
	}
	if (card2.value.compare("Seven") == 0) {
		cardValue2 = 7;
	}
	if (card2.value.compare("Eight") == 0) {
		cardValue2 = 8;
	}
	if (card2.value.compare("Nine") == 0) {
		cardValue2 = 9;
	}
	if (card2.value.compare("Ten") == 0) {
		cardValue2 = 10;
	}
	if (card2.value.compare("Jack") == 0) {
		cardValue2 = 11;
	}
	if (card2.value.compare("Queen") == 0) {
		cardValue2 = 12;
	}
	if (card2.value.compare("King") == 0) {
		cardValue2 = 13;
	}
	if (card2.value.compare("Ace") == 0) {
		cardValue2 = 14;
	}

	if (cardValue1 == cardValue2) {
		std::cout << card1.value << " of " << card1.suit << " and " << card2.value << " of " << card2.suit << " have the same value" << std::endl;
	}
	else if (cardValue1 > cardValue2) {
		std::cout << card1.value << " of " << card1.suit << " has a greater value than the " << card2.value << " of " << card2.suit << std::endl;
	}
	else {
		std::cout << card1.value << " of " << card1.suit << " has a less value than the " << card2.value << " of " << card2.suit << std::endl;
	}
}

int Card::compareValues(Card compare) {
	int cardValue1;
	int cardValue2;

	if (this->value.compare("Two") == 0) {
		cardValue1 = 2;
	}
	if (this->value.compare("Three") == 0) {
		cardValue1 = 3;
	}
	if (this->value.compare("Four") == 0) {
		cardValue1 = 4;
	}
	if (this->value.compare("Five") == 0) {
		cardValue1 = 5;
	}
	if (this->value.compare("Six") == 0) {
		cardValue1 = 6;
	}
	if (this->value.compare("Seven") == 0) {
		cardValue1 = 7;
	}
	if (this->value.compare("Eight") == 0) {
		cardValue1 = 8;
	}
	if (this->value.compare("Nine") == 0) {
		cardValue1 = 9;
	}
	if (this->value.compare("Ten") == 0) {
		cardValue1 = 10;
	}
	if (this->value.compare("Jack") == 0) {
		cardValue1 = 11;
	}
	if (this->value.compare("Queen") == 0) {
		cardValue1 = 12;
	}
	if (this->value.compare("King") == 0) {
		cardValue1 = 13;
	}
	if (this->value.compare("Ace") == 0) {
		cardValue1 = 14;
	}
	if (compare.value.compare("Two") == 0) {
		cardValue2 = 2;
	}
	if (compare.value.compare("Three") == 0) {
		cardValue2 = 3;
	}
	if (compare.value.compare("Four") == 0) {
		cardValue2 = 4;
	}
	if (compare.value.compare("Five") == 0) {
		cardValue2 = 5;
	}
	if (compare.value.compare("Six") == 0) {
		cardValue2 = 6;
	}
	if (compare.value.compare("Seven") == 0) {
		cardValue2 = 7;
	}
	if (compare.value.compare("Eight") == 0) {
		cardValue2 = 8;
	}
	if (compare.value.compare("Nine") == 0) {
		cardValue2 = 9;
	}
	if (compare.value.compare("Ten") == 0) {
		cardValue2 = 10;
	}
	if (compare.value.compare("Jack") == 0) {
		cardValue2 = 11;
	}
	if (compare.value.compare("Queen") == 0) {
		cardValue2 = 12;
	}
	if (compare.value.compare("King") == 0) {
		cardValue2 = 13;
	}
	if (compare.value.compare("Ace") == 0) {
		cardValue2 = 14;
	}

	if (cardValue1 < cardValue2) {
		return -1;
	}

	else if (cardValue1 > cardValue2) {
		return 1;
	}

	else {
		return 0;
	}
}
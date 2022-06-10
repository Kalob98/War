#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <random>

//#include <algorithm>

#include "deck.h"

static std::random_device rd;
static std::mt19937 rng(rd());

Deck::Deck() {
	//arrays used to populate the deck
	std::string num[] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
	std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	//populating the array
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card* card = new Card(num[j], suits[i]);
			this->deck.push_back(card);
		}
	}
}

Deck::~Deck() {
	//clears the deck
	for (int i = 0; i < 52; i++) {
		delete this->deck[i];
	}
}

void Deck::shuffle() {
	while (!shuffledDeck.empty()) {
		shuffledDeck.pop();

	}

	//auto rng = std::default_random_engine{};
	std::shuffle(deck.begin(), deck.end(), rng);

	for (int i = 0; i < deck.size(); i++) {
		shuffledDeck.push(deck[i]);
	}
}

Card* Deck::drawCard() {
	//takes the top card and returns it and pops it off the top
	Card* topOfDeck = shuffledDeck.top();
	shuffledDeck.pop();

	return topOfDeck;
}

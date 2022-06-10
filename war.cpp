#include <iostream>
#include <stdlib.h>
#include <string>
#include "war.h"

//used to count the number of rounds played
static int countRounds = 0;

War::War() {
}

War::~War() {
}

void War::play() {
	//obtaining playerName
	std::string playerName;
	std::cout << "Welcome to War card game. Please enter your name: ";
	std::cin >> playerName;

	//welcome message
	std::cout << "Welcome " << playerName << " to the card game WAR." << std::endl;
	std::cout << "==================================STARTING GAME==================================" << std::endl;
	std::cout << std::endl;

	//creates the deck and shuffles it
	Deck deck;
	deck.shuffle();

	//deals the deck to two players
	for (int i = 0; i < 26; i++) {
		p1.push(deck.drawCard());

		//prints the cards and who they belong to
		/*std::cout << "p1Card: ";
		p1.back()->printCard();*/

		p2.push(deck.drawCard());

		//prints the cards and who they belong to
		/*std::cout << "p2Card: ";
		p2.back()->printCard();*/
	}

	//while loop used until the game is over
	while (!isWinner(p1) and !isWinner(p2)) {
		//counts the number of rounds played
		countRounds++;

		//memory locations of cards
		Card* p1Card = p1.front();
		Card* p2Card = p2.front();

		//card values
		Card temp1 = *p1.front();
		Card temp2 = *p2.front();

		//prints the card for the user
		std::cout << playerName << "'s Card: ";
		temp1.printCard();

		std::cout << "Computer's Card: ";
		temp2.printCard();
		std::cout << std::endl;

		//compares the values of the two cards.
		int compare = temp1.compareValues(temp2);

		//used to pop the cards after war
		int popSize = 0;

		//switch statement used to place cards in the winning hand
		switch (compare) {
		//p1 = p2
		case 0:
			std::cout << "WAR!" << std::endl;
			war(p1, p2, playerName);

			//popping the number of cards used in war
			popSize = std::max(p1WarWin.size(), p2WarWin.size()) / 2;
			/*std::cout << "p1WarWin: " << p1WarWin.size() << std::endl;
			std::cout << "p2WarWin: " << p2WarWin.size() << std::endl;*/
			for (int i = 0; i < popSize; i++) {
				p1.pop();
				p2.pop();
			}

			//if player1 won war
			if (p1WarWin.size() > p2WarWin.size()) {
				while (!p1WarWin.empty()) {
					p1.push(p1WarWin.front());
					p1WarWin.pop();
				}
			}

			//if player2 won war
			else {
				while (!p2WarWin.empty()) {
					p2.push(p2WarWin.front());
					p2WarWin.pop();
				}
			}
			break;
		//p1 > p2
		case 1:
			std::cout << playerName << " wins this hand." << std::endl;
			p1.pop();
			p1.push(p1Card);

			p2.pop();
			p1.push(p2Card);
			break;
		//p1 < p2
		case -1:
			std::cout << "Computer wins this hand." << std::endl;
			p1.pop();
			p2.push(p1Card);

			p2.pop();
			p2.push(p2Card);
			break;
		}

		if (isWinner(p1)) {
			std::cout << playerName << " has won this game of war." << std::endl;
		}

		else if (isWinner(p2)) {
			std::cout << "The computer has won this game of war." << std::endl;
		}

		/*else {
			std::string nextRound;
			std::cout << "Press D to deal the next round: ";
			std::cin >> nextRound;
		}*/

		std::cout << std::endl;
		std::cout << "p1 deck size: " << p1.size() << std::endl;
		std::cout << "p2 deck size: " << p2.size() << std::endl;
		std::cout << std::endl;

		while (!p1WarWin.empty()) {
			p1WarWin.pop();
		}

		while (!p2WarWin.empty()) {
			p2WarWin.pop();
		}

		std::cout << "count: " << countRounds << std::endl;
	}

	std::cout << "It took " << countRounds << " rounds to finish the game." << std::endl;
}

//use & for reference
void War::war(std::queue<Card*> p1, std::queue<Card*> p2, std::string playerName) {
	//if the player can not complete war they lose
	if (p1.size() < 3) {
		while (!p1.empty()) {
			Card* temp = p1.front();
			p2WarWin.push(temp);
			p1.pop();
		}
	}

	else if (p2.size() < 3) {
		while (!p2.empty()) {
			Card* temp = p2.front();
			p1WarWin.push(temp);
			p2.pop();
		}
	}

	else {
		for (int i = 0; i < 2; i++) {
			Card* p1WarCard = p1.front();
			p1WarWin.push(p1WarCard);
			p2WarWin.push(p1WarCard);
			p1.pop();

			Card* p2WarCard = p2.front();
			p1WarWin.push(p2WarCard);
			p2WarWin.push(p2WarCard);
			p2.pop();
		}

		Card warTemp1 = *p1.front();
		Card warTemp2 = *p2.front();

		std::cout << playerName << "'s Card during WAR: ";
		warTemp1.printCard();

		std::cout << "Computer's Card during WAR: ";
		warTemp2.printCard();
		std::cout << std::endl;

		Card* temp1 = p1.front();
		Card* temp2 = p2.front();

		int compare = warTemp1.compareValues(warTemp2);
		switch (compare) {
			//p1 = p2
		case 0:
			std::cout << "Another WAR!" << std::endl;
			war(p1, p2, playerName);
			break;
			//p1 > p2
		case 1:
			p1WarWin.push(temp1);
			p1WarWin.push(temp2);
			std::cout << playerName << " wins this WAR!" << std::endl;
			//return p1WarWin;
			break;
			//p1 < p2
		case -1:
			p2WarWin.push(temp1);
			p2WarWin.push(temp2);
			std::cout << "Computer wins this WAR!" << std::endl;
			//return p2WarWin;
			break;
		}
	}
}

bool War::isWinner(std::queue<Card*> x) {
	if (x.size() == 52) {
		return true;
	}

	return false;
}
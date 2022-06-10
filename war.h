#ifndef WAR_H
#define WAR_H

#include <string>
#include "deck.h"
#include "card.h"
#include <queue>

class War {
public:
	War();
	~War();

public:
	void play();

protected:
	//std::queue<Card*>
	void war(std::queue<Card*> p1, std::queue<Card*> p2, std::string playerName);
	bool isWinner(std::queue<Card*> x);

	std::queue<Card*> p1;
	std::queue<Card*> p2;
	std::queue<Card*> p1WarWin;
	std::queue<Card*> p2WarWin;
};

#endif
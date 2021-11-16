#pragma once
#include "Player.h"

class Game {
private:
	Player* player1;
	Player* player2;
	int moves;
	Board board;

public:
	Game();
	~Game();
	void selectPlayers();
	Player* nextPlayer() const;
	bool isRunning() const;
	void play();
	void announceWinner();



};
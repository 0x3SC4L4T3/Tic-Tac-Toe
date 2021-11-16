#include "Game.h"

int main() {

	Game tictactoe;
	tictactoe.selectPlayers();
	tictactoe.play();
	tictactoe.announceWinner();
	return 0;
}
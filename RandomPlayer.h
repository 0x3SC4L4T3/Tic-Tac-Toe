#pragma once
#include "ComputerPlayer.h"

class RandomPlayer: public ComputerPlayer {
public:
	RandomPlayer(Piece);
	void makeMove(Board& B) const override;
};
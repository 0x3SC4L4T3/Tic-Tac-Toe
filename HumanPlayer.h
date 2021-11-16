#pragma once
#include "Player.h"
class HumanPlayer : public Player{
public:
	HumanPlayer(const string&, Piece);
	void makeMove(Board& B) const override;
};
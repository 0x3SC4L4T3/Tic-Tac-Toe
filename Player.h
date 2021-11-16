#pragma once

#include "Board.h"


class Player {
private:
	string playerName;
	Piece playerPiece;
public:
	Player(const string&, Piece);
	Piece getPiece() const;
	virtual void makeMove(Board&) const = 0;
	const std::string& name();



};
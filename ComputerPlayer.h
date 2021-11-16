#pragma once
#include "Player.h"

static char computerAddress = 'A';
class ComputerPlayer : public Player {
public:
	ComputerPlayer(Piece);
};
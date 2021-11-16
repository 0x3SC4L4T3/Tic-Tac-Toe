#include "RandomPlayer.h"


/**
* Parameterized constructor for Computer player that is a derived from base class "Computer Player",
* the constructor of Computer Player is passed to perform Inheritance, this constructor is different
* from the human class, this only takes Piece and name is decided on run time using ComputerPlayer constructor.
*/
RandomPlayer::RandomPlayer(Piece P): ComputerPlayer(P)
{	
}

/**
* The function is virtual in Player class and a bot is making move on the board by specifying the index randomly between 0 and 8
*/
void RandomPlayer::makeMove(Board& B) const
{
	int index = (rand() % 9) + 0;
	B.makeMove(this->getPiece(), index);
}

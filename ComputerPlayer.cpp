#include "ComputerPlayer.h"

/**
* Parameterized constructor for Computer player that is a derived from base class "player",
* the constructor of Player is passed to perform Inheritance, this constructor is different
* from the human class, this only takes Piece and name is decided on run time.
*/

ComputerPlayer::ComputerPlayer(Piece P) : Player("Computer" + computerAddress++, P)
{
}

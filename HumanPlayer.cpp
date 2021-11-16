#include "HumanPlayer.h"
#include "Player.h"
/**
* Parameterized constructor for Human player that is a derived from base class "player", 
* the constructor of Player is passed to perform Inheritance
*/
HumanPlayer::HumanPlayer(const string& _name, Piece p) : Player(_name, p) {

}

/**
* The function is virtual in Player class and a human is making move on the board by specifying the index
*/
void HumanPlayer::makeMove(Board& B) const
{
	cout << "Enter the index of place: ";
	int index;
	cin >> index;
	B.makeMove(this->getPiece(), index);
}

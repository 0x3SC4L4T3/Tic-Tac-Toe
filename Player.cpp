#include "Player.h"

/**
* Parameterized constructor for the Player class that takes name and piece as an argument
*/
Player::Player(const string& _name, Piece p)
{
    this->playerName = _name;
    this->playerPiece = p;

}

/**
* Returns the piece for the current player
*/

Piece Player::getPiece() const
{
    return this->playerPiece;
}

/**
* Returns the Name for the current player
*/
const std::string& Player::name()
{
    return this->playerName;
}


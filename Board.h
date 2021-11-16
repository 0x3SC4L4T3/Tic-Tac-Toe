#pragma once

#include <string>
#include <iostream>
using namespace std;
/**
* Enum class to specify the symbol to be placed on the board by each player
*/
enum class Piece { empty = ' ', first = 'X', second = 'O' };

class Board {

private:
	Piece arr[9];
public:
	Board();
	void clear();
	void display();
	void makeMove(Piece, int);
	void undoMove(int);
	bool isLegal(Piece, int) const;
	bool isWinner(Piece) const;
	bool isFull() const;


};
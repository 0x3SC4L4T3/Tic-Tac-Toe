#include "Board.h"

/**
* A << operator overloaded function to print the value of Piece.
*/
std::ostream& operator<<(std::ostream& os, const Piece Token)
{
	switch (Token)
	{
	case Piece::empty:
		os << ' ';
		break;
	case Piece::first:
		os << 'X';
		break;
	case Piece::second:
		os << 'O';
		break;
	}
	return os;
}


/**
* Parameterized constructor for Board class that initializes the array to ' ' 
*/
Board::Board()
{
	for (int i = 0; i < 9; i++) {
		arr[i] = Piece::empty;
	}
}


/**
* This function clears the board that means place ' ' from 0th to 8th index
*/
void Board::clear()
{
	for (int i = 0; i < 9; i++) {
		arr[i] = Piece::empty;
	}
}


/**
* The function displays the board in the format defined in the document
*/
void Board::display()
{

	cout << "+-----------+\n|";
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " | ";
	}

	cout << "\n+-----------+\n|";
	for (int i = 3; i < 6; i++) {
		cout << arr[i] << " | ";

	}
	cout << "\n+-----------+\n|";
	for (int i = 6; i < 9; i++) {
		cout << arr[i] << " | ";

	}
	cout << "\n+-----------+\n";
}


/**
* If the current index is legal place then insert the player's piece to the index requested
*/
void Board::makeMove(Piece P, int index)
{
	if (isLegal(P,index)) {
		arr[index] = P;
	}
	else {
		cout << "Invalid Move\n";
	}
	
	
}

/**
* This function places ' ' to the index requested by the user, that we can say undo move during the program execution
*/
void Board::undoMove(int index)
{
	arr[index] = Piece::empty;
}

/**
* This function checks if the index is legal and empty slot on the board or not
*/
bool Board::isLegal(Piece P, int index) const
{
	return index >= 0 && index < 9 && arr[index] == Piece::empty;
}

/**
* This functions checks the winner row wise, coloumn wise and diagonally
*/

bool Board::isWinner(Piece P) const
{
	if ((arr[0] == P && arr[1] == P && arr[2] == P) || 
		(arr[3] == P && arr[4] == P && arr[5] == P) || 
		(arr[6] == P && arr[7] == P && arr[8] == P) ||
		(arr[0] == P && arr[3] == P && arr[6] == P) ||
		(arr[1] == P && arr[4] == P && arr[7] == P) ||
		(arr[2] == P && arr[5] == P && arr[8] == P) ||
		(arr[0] == P && arr[4] == P && arr[8] == P) ||
		(arr[2] == P && arr[4] == P && arr[6] == P) ) 
	{
		return true;
	}
	return false;
}

/**
* This function checks if the board is full or not, if the count is 9 that means all the places are filled
*/
bool Board::isFull() const
{
	int count = 0;
	for (int i = 0; i < 9; i++) {
		if (arr[i] != Piece::empty) {
			count++;
		}
	}
	if (count == 9) {
		return true;
	}
	return false;
}

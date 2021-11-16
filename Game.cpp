#include "Game.h"
#include "Player.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "ComputerPlayer.h"

/**
* A game class default constructor that initializes the player1 and player2 to null and set moves to 0
* to keep track of player turn later in play() function
*/
Game::Game()
{
    this->player1 = NULL;
    this->player2 = NULL;
    moves = 0;
}

/**
* The destructor of game class deleting player1 and player2 that are allocated dynamically
*/
Game::~Game()
{
    if (player1 != NULL) {
        delete player1;
    }
    if (player2 != NULL) {
        delete player2;
    }

    player1 = NULL;
    player2 = NULL;
}

/**
* The user can select players in this function. If a type is 1 then the player object will be 
* assigned a human player and if type is 2 then the player will be assigned a randomplayer
*/
void Game::selectPlayers()
{

    int type1, type2;
    cout << "Please select Player 1 type:\n1. Human Player\n2. Computer Player\n";
    cin >> type1;
    if (type1 == 1) {
        cout << "Enter Name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        player1 = new HumanPlayer(name, Piece::first);
    }
    else if (type1 == 2) {
        player1 = new RandomPlayer(Piece::first);
    }
    cout << "Please select Player 2 type:\n1. Human Player\n2. Computer Player\n";
    cin >> type2;

    if (type2 == 1) {
        cout << "Enter Name: ";
        string name;
        cin.ignore();
        getline(cin, name);
        player2 = new HumanPlayer(name, Piece::second);
    }
    else if (type2 == 2) {
        player2 = new RandomPlayer(Piece::second);
    }
}
/**
* We kept track of player's turn using the variable "moves", if it is odd then it's player2 turn
* else player1 turns since we started moves at 0 with the turn of player1
*/
Player* Game::nextPlayer() const
{
    if (moves % 2 == 0) {
        cout << player1->name() << " turn now: \n";
        return player1;
    }
    cout << player2->name() << " turn now: \n";
    return player2;
}

/**
* This function tells if there is still no one is winner and there are spaces on the board
*/
bool Game::isRunning() const
{
    return !board.isFull() && !board.isWinner(player1->getPiece()) && !board.isWinner(player2->getPiece());
}

/**
* This function actually calls all the main functions that display board, take input, and keep track of moves for turns.
*/
void Game::play()
{
    while (isRunning()) {
        board.display();
        nextPlayer()->makeMove(board);
        moves++;
    }

}

/**
* This function checks who is the winner when the board is full and the game is ended
*/
void Game::announceWinner()
{
    board.display();
    if (board.isWinner(player1->getPiece())) {
        cout << player1->name() << " is a winner\n";
    }else if(board.isWinner(player2->getPiece())) {
        cout << player2->name() << " is a winner\n";
    }
    else {
        cout << "Match is drawn!\n";
    }
}

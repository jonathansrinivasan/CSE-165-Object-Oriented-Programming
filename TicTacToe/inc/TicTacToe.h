#ifndef TICTACTOE_H
#define TICTACTOE_H

//#include <vector>
#include <server.h>
#include <Square.h>

class TicTacToe{

	std::vector<int> board;

public:
	int round;
	int winner;
	TicTacToe();					// Default constructor
	//TicTacToe(const TicTacToe&);	// Copy Constructor

	//std::vector<std::vector<Square>> mainBoard;
	Square mainBoard[3][3];
	ucm::json getBoard();
	void gameOver();
	int checkWinner();

	ucm::json clicked(int, int);

	//~TicTacToe();					// Destructor

};



#endif
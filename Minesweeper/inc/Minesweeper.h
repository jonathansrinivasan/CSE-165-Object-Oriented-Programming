#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <BoardGame.h>
#include <Square.h>
#include <iostream>
#include <limits>

class Minesweeper: public BoardGame {
	Minesweeper(); // private constructor, it can not be called

public:
	int dice;
	int setDice;
	int coin;
	
	bool newGame;

	bool wonGame;
	bool lostGame;

	int numBombs;
	int row;
	int col;

	Square mainBoard[9][9];

	void recursive(int, int);
	int numNeighbors(int, int);
	void createBoard(int, int);
	
	void postBlast();
	bool checkBlasted(int, int);

	bool checkWinner();

	Minesweeper(int, int, int);	

	void reset();

	void handle(int, int, MouseButton=left);

	ucm::json getBoard();

	~Minesweeper();
};


#endif
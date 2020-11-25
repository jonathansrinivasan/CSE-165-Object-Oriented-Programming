#ifndef GAMEOFLIFE
#define GAMEOFLIFE

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{
public:
	bool running;
	int row;
	int col;

	Cell mainBoard[100][100];
	GameOfLife();
	
	int numNeighbors(Cell board[100][100], int x, int y);
	void start();
	void stop();
	void advance();

	ucm::json getBoard();

};

#endif

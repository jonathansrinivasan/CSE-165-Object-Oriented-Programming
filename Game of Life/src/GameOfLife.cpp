#include <GameOfLife.h>
#include <iostream>

GameOfLife::GameOfLife(){
	running = false;

	/*
	row = 5;
	col = 5;
	*/

	int dice = rand() % 10;

	if(dice >= 0 && dice <= 6){
		row = rand()%21 + 4;
		col = row;
	}else if( dice == 7 || dice == 8){
		row = rand()%25 + 25;
		col = row;
	}else{
		row = rand()% 45 + 50;
		col = row;
	}
		
	/*
	mainBoard[2][1].makeAlive();
	mainBoard[2][2].makeAlive();
	mainBoard[2][3].makeAlive();
	*/

	int coin = rand() % 3;

	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			if(coin == 0)
				mainBoard[i][j].makeAlive();
			
			coin = rand() % 3;
		}
	}
}


void GameOfLife::start(){
	running = true;
}

void GameOfLife::stop(){
	running = false;
}

int GameOfLife::numNeighbors(Cell board[100][100], int x, int y){
	int answer = 0;

	if(x == 0 && y == 0){
		if(board[x + 1][y].getValue() == true)
			answer ++;
		if(board[x][y + 1].getValue() == true)
			answer ++;
		if(board[x + 1][y + 1].getValue() == true)
			answer ++;
	}else if(x == row - 1 && y == 0){
		if(board[x - 1][y].getValue() == true)
			answer ++;
		if(board[x][y + 1].getValue() == true)
			answer ++;
		if(board[x - 1][y + 1].getValue() == true)
			answer ++;
	}else if(x == 0 && y == col - 1){
		if(board[x + 1][y].getValue() == true)
			answer ++;
		if(board[x][y - 1].getValue() == true)
			answer ++;
		if(board[x + 1][y - 1].getValue() == true)
			answer ++;
	}else if(x == row - 1 && y == col - 1){
		if(board[x - 1][y].getValue() == true)
			answer ++;
		if(board[x][y - 1].getValue() == true)
			answer ++;
		if(board[x - 1][y - 1].getValue() == true)
			answer ++;
	}else if((x == 0) && (y >= 1 && y <= col - 2)){
		if(board[x][y - 1].getValue() == true)
			answer ++;
		if(board[x + 1][y - 1].getValue() == true)
			answer ++;
		if(board[x + 1][y].getValue() == true)
			answer ++;
		if(board[x + 1][y + 1].getValue() == true)
			answer ++;
		if(board[x][y + 1].getValue() == true)
			answer ++;
	}else if((y == 0) && (x >= 1 && x <= row - 2)){
		if(board[x - 1][y].getValue() == true)
			answer ++;
		if(board[x - 1][y + 1].getValue() == true)
			answer ++;
		if(board[x][y + 1].getValue() == true)
			answer ++;
		if(board[x + 1][y + 1].getValue() == true)
			answer ++;
		if(board[x + 1][y].getValue() == true)
			answer ++;
	}else if((x == row - 1) && (y >= 1 && y <= col - 2)){
		if(board[x][y - 1].getValue() == true)
			answer ++;
		if(board[x - 1][y - 1].getValue() == true)
			answer ++;
		if(board[x - 1][y].getValue() == true)
			answer ++;
		if(board[x - 1][y + 1].getValue() == true)
			answer ++;
		if(board[x][y + 1].getValue() == true)
			answer ++;
	}else if((y == col - 1) && (x >= 1 || x <= row - 2)){
		if(board[x - 1][y].getValue() == true)
			answer ++;
		if(board[x - 1][y - 1].getValue() == true)
			answer ++;
		if(board[x][y - 1].getValue() == true)
			answer ++;
		if(board[x + 1][y - 1].getValue() == true)
			answer ++;
		if(board[x + 1][y].getValue() == true)
			answer ++;
	}else{
		if(board[x - 1][y - 1].getValue() == true)
			answer ++;
		if(board[x - 1][y].getValue() == true)
			answer ++;
		if(board[x - 1][y + 1].getValue() == true)
			answer ++;
		if(board[x][y - 1].getValue() == true)
			answer ++;
		if(board[x][y + 1].getValue() == true)
			answer ++;
		if(board[x + 1][y - 1].getValue() == true)
			answer ++;
		if(board[x + 1][y].getValue() == true)
			answer ++;
		if(board[x + 1][y + 1].getValue() == true)
			answer ++;
	}

	return answer;
}

void GameOfLife::advance(){
	Cell tempBoard[100][100];

	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			tempBoard[i][j] = mainBoard[i][j];
		}
	}

	
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			if(mainBoard[i][j].getValue() == true){
				if(numNeighbors(tempBoard, i, j) < 2 || numNeighbors(tempBoard, i, j) > 3)
					mainBoard[i][j].makeDead();
			}else if(mainBoard[i][j].getValue() == false){
				if(numNeighbors(tempBoard, i, j) == 3)
					mainBoard[i][j].makeAlive();
			}
		}
	}
	
}

ucm::json GameOfLife::getBoard(){
	ucm::json result;
	std::vector<bool> finalAns;

	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			finalAns.push_back(mainBoard[i][j].getValue());
		}
		result.push_back(finalAns);
		finalAns.clear();
	}

	/*
	result.push_back({mainBoard[0][0].getValue(), mainBoard[0][1].getValue(), mainBoard[0][2].getValue(), mainBoard[0][3].getValue(), mainBoard[0][4].getValue()});
	result.push_back({mainBoard[1][0].getValue(), mainBoard[1][1].getValue(), mainBoard[1][2].getValue(), mainBoard[1][3].getValue(), mainBoard[1][4].getValue()});	
	result.push_back({mainBoard[2][0].getValue(), mainBoard[2][1].getValue(), mainBoard[2][2].getValue(), mainBoard[2][3].getValue(), mainBoard[2][4].getValue()});
	result.push_back({mainBoard[3][0].getValue(), mainBoard[3][1].getValue(), mainBoard[3][2].getValue(), mainBoard[3][3].getValue(), mainBoard[3][4].getValue()});
	result.push_back({mainBoard[4][0].getValue(), mainBoard[4][1].getValue(), mainBoard[4][2].getValue(), mainBoard[4][3].getValue(), mainBoard[4][4].getValue()});
	*/

	return result;
}



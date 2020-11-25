#include <Minesweeper.h>
#include <stdlib.h> 

Minesweeper::Minesweeper(){

}

Minesweeper::Minesweeper(int rows, int cols, int bombs){
	std::cout << "Making a game of " << rows << " x " << cols << " with " << bombs << " bombs" << std::endl;
	row = rows;
	col = cols; 
	numBombs = bombs;

	newGame = true;

	wonGame = false;
	lostGame = false;

	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			mainBoard[i][j].makeBlank();
		}
	}

}	

void Minesweeper::reset(){
	std::cout << "Reseting the game" << std::endl;
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			mainBoard[i][j].makeBlank();
		}
	}
}

int Minesweeper::numNeighbors(int x, int y){
	int answer = 0;

	if(x == 0 && y == 0){
		if(mainBoard[x + 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y + 1].isBomb() == true)
			answer ++;
	}else if(x == row - 1 && y == 0){
		if(mainBoard[x - 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y + 1].isBomb() == true)
			answer ++;
	}else if(x == 0 && y == col - 1){
		if(mainBoard[x + 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y - 1].isBomb() == true)
			answer ++;
	}else if(x == row - 1 && y == col - 1){
		if(mainBoard[x - 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y - 1].isBomb() == true)
			answer ++;
	}else if((x == 0) && (y >= 1 && y <= col - 2)){
		if(mainBoard[x][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x][y + 1].isBomb() == true)
			answer ++;
	}else if((y == 0) && (x >= 1 && x <= row - 2)){
		if(mainBoard[x - 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y].isBomb() == true)
			answer ++;
	}else if((x == row - 1) && (y >= 1 && y <= col - 2)){
		if(mainBoard[x][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x][y + 1].isBomb() == true)
			answer ++;
	}else if((y == col - 1) && (x >= 1 || x <= row - 2)){
		if(mainBoard[x - 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y].isBomb() == true)
			answer ++;
	}else{
		if(mainBoard[x - 1][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x - 1][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x][y + 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y - 1].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y].isBomb() == true)
			answer ++;
		if(mainBoard[x + 1][y + 1].isBomb() == true)
			answer ++;
	}

	return answer;
}

bool Minesweeper::checkWinner(){
	bool answer = true;

	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			if(mainBoard[i][j].isBomb() == true && mainBoard[i][j].isFlag() == false){
				answer = false;
				return answer;
			}

			if(mainBoard[i][j].isBomb() == false && mainBoard[i][j].isOpen() == false){
				answer = false;
				return answer;
			}
		}
	}

	return answer;
}

void Minesweeper::recursive(int x, int y){
	if(dice <= setDice){
		mainBoard[x][y].blasted();
		mainBoard[x][y].setValue(0);
		mainBoard[x][y].openSquare();
		dice ++;

		if(x == 0 && y == 0){
			coin = rand()%2;

			if(coin == 0){
				recursive(x + 1, y);
			}else if(coin == 1){
				recursive(x, y + 1);
			}

		}else if(x == row - 1 && y == 0){
			coin = rand()%2;

			if(coin == 0){
				recursive(x - 1, y);
			}else if(coin == 1){
				recursive(x, y + 1);
			}

		}else if(x == 0 && y == col - 1){
			coin = rand()%2;

			if(coin == 0){
				recursive(x + 1, y);
			}else if(coin == 1){
				recursive(x, y - 1);
			}

		}else if(x == row - 1 && y == col - 1){
			coin = rand()%2;

			if(coin == 0){
				recursive(x - 1, y);
			}else if(coin == 1){
				recursive(x, y - 1);
			}

		}else if((x == 0) && (y >= 1 && y <= col - 2)){
			coin = rand()%3;

			if(coin == 0){
				recursive(x, y - 1);
			}else if(coin == 1){
				recursive(x + 1, y);
			}else if(coin == 2){
				recursive(x, y + 1);
			}

		}else if((y == 0) && (x >= 1 && x <= row - 2)){
			coin = rand()%3;

			if(coin == 0){
				recursive(x - 1, y);
			}else if(coin == 1){
				recursive(x, y + 1);
			}else if(coin == 2){
				recursive(x + 1, y);
			}

		}else if((x == row - 1) && (y >= 1 && y <= col - 2)){
			coin = rand()%3;

			if(coin == 0){
				recursive(x, y - 1);
			}else if(coin == 1){
				recursive(x - 1, y);
			}else if(coin == 2){
				recursive(x, y + 1);
			}

		}else if((y == col - 1) && (x >= 1 || x <= row - 2)){
			coin = rand()%3;

			if(coin == 0){
				recursive(x - 1, y);
			}else if(coin == 1){
				recursive(x, y - 1);
			}else if(coin == 2){
				recursive(x + 1, y);
			}

		}else{
			coin = rand()%4;

			if(coin == 0){
				recursive(x - 1, y);
			}else if(coin == 1){
				recursive(x + 1, y);
			}else if(coin == 2){
				recursive(x, y + 1);
			}else if(coin == 3){
				recursive(x, y - 1);
			}
		}
	}
	
}

bool Minesweeper::checkBlasted(int x, int y){
	bool answer = false;

	if(x == 0 && y == 0){
		if(mainBoard[x + 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y + 1].isBlasted() == true)
			answer = true;
	}else if(x == row - 1 && y == 0){
		if(mainBoard[x - 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y + 1].isBlasted() == true)
			answer = true;
	}else if(x == 0 && y == col - 1){
		if(mainBoard[x + 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y - 1].isBlasted() == true)
			answer = true;
	}else if(x == row - 1 && y == col - 1){
		if(mainBoard[x - 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y - 1].isBlasted() == true)
			answer = true;
	}else if((x == 0) && (y >= 1 && y <= col - 2)){
		if(mainBoard[x][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y + 1].isBlasted() == true)
			answer = true;
	}else if((y == 0) && (x >= 1 && x <= row - 2)){
		if(mainBoard[x - 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y].isBlasted() == true)
			answer = true;
	}else if((x == row - 1) && (y >= 1 && y <= col - 2)){
		if(mainBoard[x][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y + 1].isBlasted() == true)
			answer = true;
	}else if((y == col - 1) && (x >= 1 || x <= row - 2)){
		if(mainBoard[x - 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y].isBlasted() == true)
			answer = true;
	}else{
		if(mainBoard[x - 1][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x - 1][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x][y + 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y - 1].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y].isBlasted() == true)
			answer = true;
		if(mainBoard[x + 1][y + 1].isBlasted() == true)
			answer = true;
	}

	return answer;
}

void Minesweeper::postBlast(){
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			if(mainBoard[i][j].getValue() == 0 && checkBlasted(i, j) == true){
				mainBoard[i][j].blasted();
				mainBoard[i][j].openSquare();
			}
		}
	}
}

void Minesweeper::createBoard(int x, int y){
	coin = 0;
	dice = 0;
	setDice = rand()%2 + 3;
	recursive(x, y);

	int randX = 0;
	int randY = 0;

	for(int k = 0; k < numBombs*2; k ++){
		randX = rand()%row;
		randY = rand()%col;

		if(mainBoard[randX][randY].isBlasted() == false){
			mainBoard[randX][randY].makeBomb();
		}
	}

	int temp = 0;
	for(int i = 0; i < row; i ++){
		for(int j = 0; j < col; j ++){
			if(mainBoard[i][j].isBomb() == false){
				temp = numNeighbors(i, j);
				mainBoard[i][j].setValue(temp);
			}
		}
	}

	postBlast();
}

void Minesweeper::handle(int x, int y, MouseButton button){
	std::string btn;

	if (button == left){
		//btn = "left";

		if(newGame == true){
			createBoard(x, y);
			newGame = false;
		}else{
			if(mainBoard[x][y].isBomb() == true){
				mainBoard[x][y].openSquare();
				lostGame = true;
			}

			if(checkWinner() == false){
				mainBoard[x][y].openSquare();
			}else{
				wonGame = true;
			}
		}

	}
	else if (button == right){
		//btn = "right";

		if(mainBoard[x][y].isFlag() == false && mainBoard[x][y].isOpen() == false){
			mainBoard[x][y].makeFlag();
		}else if(mainBoard[x][y].isFlag() == true && mainBoard[x][y].isOpen() == false){
			mainBoard[x][y].unmakeFlag();
		}
	}
	else {
		//btn = "unknown";
	}

	//std::cout << "Handling a " << btn << " click on " << x << ", " << y << std::endl;
}

ucm::json Minesweeper::getBoard(){
	ucm::json board;
	ucm::json openBoard;
	ucm::json flagBoard;

	for(int i = 0; i < 9; i++){
        board.push_back({mainBoard[i][0].getValue(),mainBoard[i][1].getValue(),mainBoard[i][2].getValue(),mainBoard[i][3].getValue(),mainBoard[i][4].getValue(),mainBoard[i][5].getValue(),mainBoard[i][6].getValue(),mainBoard[i][7].getValue(),mainBoard[i][8].getValue()});
        openBoard.push_back({mainBoard[i][0].isOpen(),mainBoard[i][1].isOpen(),mainBoard[i][2].isOpen(),mainBoard[i][3].isOpen(),mainBoard[i][4].isOpen(),mainBoard[i][5].isOpen(),mainBoard[i][6].isOpen(),mainBoard[i][7].isOpen(),mainBoard[i][8].isOpen()});
        flagBoard.push_back({mainBoard[i][0].isFlag(),mainBoard[i][1].isFlag(),mainBoard[i][2].isFlag(),mainBoard[i][3].isFlag(),mainBoard[i][4].isFlag(),mainBoard[i][5].isFlag(),mainBoard[i][6].isFlag(),mainBoard[i][7].isFlag(),mainBoard[i][8].isFlag()});   
    }

	ucm::json result;
	result["board"] = board;
	result["open_board"] = openBoard;
	result["flag_board"] = flagBoard;
	result["won_game"] = wonGame;
	result["lost_game"] = lostGame;

	return result;
}

Minesweeper::~Minesweeper(){

}

#include <TicTacToe.h>

TicTacToe::TicTacToe(){
	for (int i = 0; i < 10; i++){
		board.push_back(0); // make the board empty
	}

	round = 0;
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 3; j ++){
			mainBoard[i][j].makeBlank();
		}
	}
}

int TicTacToe::checkWinner(){
	//0 = no one won
    //1 = X won
    //2 = O won
    //3 = tie

	//check X
	if((mainBoard[0][0].getValue() == 1) && (mainBoard[0][1].getValue() == 1) && (mainBoard[0][2].getValue() == 1)){
		return 1;
	}else if((mainBoard[1][0].getValue() == 1) && (mainBoard[1][1].getValue() == 1) && (mainBoard[1][2].getValue() == 1)){
		return 1;
	}else if((mainBoard[2][0].getValue() == 1) && (mainBoard[2][1].getValue() == 1) && (mainBoard[2][2].getValue() == 1)){
		return 1;
	}else if((mainBoard[0][0].getValue() == 1) && (mainBoard[1][0].getValue() == 1) && (mainBoard[2][0].getValue() == 1)){
		return 1;
	}else if((mainBoard[0][1].getValue() == 1) && (mainBoard[1][1].getValue() == 1) && (mainBoard[2][1].getValue() == 1)){
		return 1;
	}else if((mainBoard[0][2].getValue() == 1) && (mainBoard[1][2].getValue() == 1) && (mainBoard[2][2].getValue() == 1)){
		return 1;
	}else if((mainBoard[0][0].getValue() == 1) && (mainBoard[1][1].getValue() == 1) && (mainBoard[2][2].getValue() == 1)){
		return 1;
	}else if((mainBoard[2][0].getValue() == 1) && (mainBoard[1][1].getValue() == 1) && (mainBoard[0][2].getValue() == 1)){
		return 1;

	}else if((mainBoard[0][0].getValue() == 2) && (mainBoard[0][1].getValue() == 2) && (mainBoard[0][2].getValue() == 2)){
		//check O
		return 2;
	}else if((mainBoard[1][0].getValue() == 2) && (mainBoard[1][1].getValue() == 2) && (mainBoard[1][2].getValue() == 2)){
		return 2;
	}else if((mainBoard[2][0].getValue() == 2) && (mainBoard[2][1].getValue() == 2) && (mainBoard[2][2].getValue() == 2)){
		return 2;
	}else if((mainBoard[0][0].getValue() == 2) && (mainBoard[1][0].getValue() == 2) && (mainBoard[2][0].getValue() == 2)){
		return 2;
	}else if((mainBoard[0][1].getValue() == 2) && (mainBoard[1][1].getValue() == 2) && (mainBoard[2][1].getValue() == 2)){
		return 2;
	}else if((mainBoard[0][2].getValue() == 2) && (mainBoard[1][2].getValue() == 2) && (mainBoard[2][2].getValue() == 2)){
		return 2;
	}else if((mainBoard[0][0].getValue() == 2) && (mainBoard[1][1].getValue() == 2) && (mainBoard[2][2].getValue() == 2)){
		return 2;
	}else if((mainBoard[2][0].getValue() == 2) && (mainBoard[1][1].getValue() == 2) && (mainBoard[0][2].getValue() == 2)){
		return 2;
	}

	bool checkTie = true;
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 3; j ++){
			if(mainBoard[i][j].getValue() == 0){
				checkTie = false;
			}
		}
	}

	if(checkTie == true){
		return 3;
	}

	return 0;
}

void TicTacToe::gameOver(){
    for (int i = 0; i < 10; i++){
		board.at(i) = 0; // make the board empty
	}

	round = 0;
	for(int i = 0; i < 3; i ++){
		for(int j = 0; j < 3; j ++){
			mainBoard[i][j].makeBlank();
		}
	}
}


ucm::json TicTacToe::getBoard(){

	ucm::json ans;

	board.at(0) = mainBoard[0][0].getValue();
	board.at(1) = mainBoard[0][1].getValue();
	board.at(2) = mainBoard[0][2].getValue();
	board.at(3) = mainBoard[1][0].getValue();
	board.at(4) = mainBoard[1][1].getValue();
	board.at(5) = mainBoard[1][2].getValue();
	board.at(6) = mainBoard[2][0].getValue();
	board.at(7) = mainBoard[2][1].getValue();
	board.at(8) = mainBoard[2][2].getValue();

	ans["board"] = board;

	return ans;

}


ucm::json TicTacToe::clicked(int x, int y){
	ucm::json ans;

	if(round % 2 == 0){
        if(mainBoard[x][y].getValue() == 0){
			mainBoard[x][y].makeX();
			round++;
		} 
    }else{
        if(mainBoard[x][y].getValue() == 0){
			mainBoard[x][y].makeO();
			round++; 
		}
    }

	board.at(0) = mainBoard[0][0].getValue();
	board.at(1) = mainBoard[0][1].getValue();
	board.at(2) = mainBoard[0][2].getValue();
	board.at(3) = mainBoard[1][0].getValue();
	board.at(4) = mainBoard[1][1].getValue();
	board.at(5) = mainBoard[1][2].getValue();
	board.at(6) = mainBoard[2][0].getValue();
	board.at(7) = mainBoard[2][1].getValue();
	board.at(8) = mainBoard[2][2].getValue();

	if(checkWinner() == 1){
		board.at(9) = 1;
        ans["board"] = board;
        ans["winner"] = 1;
        gameOver();
	}else if(checkWinner() == 2){
		board.at(9) = 2;
        ans["board"] = board;
        ans["winner"] = 2;
        gameOver();
	}else if(checkWinner() == 3){
		board.at(9) = 3;
        ans["board"] = board;
        ans["winner"] = 3;
        gameOver();
	}else{
        ans["board"] = board;
        ans["winner"] = 0;
    }

	return ans;
}

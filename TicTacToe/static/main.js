function winnerPresent(board){
	if(board[9] == 1){
		window.alert("X is the winner!");
	}else if(board[9] == 2){
		window.alert("O is the winner!");
	}else if(board[9] == 3){
		window.alert("It is a tie!");
	}
}

function updateBoard(board){
    
    for(var i = 0; i < 9; i ++){
        if (board[i] == 1){
			board[i] = '<img src="x.png" style="width:100px; height:100px">';
		}
		else if (board[i] == 2){
			board[i] = '<img src="o.png" style="width:100px; height:100px">';
		}
		else{
			board[i] = "";
		}
    }

	$("#00").html(board[0]);
	$("#01").html(board[1]);
	$("#02").html(board[2]);

	$("#10").html(board[3]);
	$("#11").html(board[4]);
	$("#12").html(board[5]);

	$("#20").html(board[6]);
	$("#21").html(board[7]);
    $("#22").html(board[8]);

    if(board[9] != 0){
        if(board[9] == 1){
            window.alert("X is the winner!"); 
        }else if(board[9] == 2){
            window.alert("O is the winner!");
        }else if(board[9] == 3){
            window.alert("It is a tie!");
        }
    }
}

function startOver(board){
    for(var i = 0; i < 9; i ++){
        board[i] = "";
    }
    board[9] = 0;

    $("#00").html(board[0]);
	$("#01").html(board[1]);
	$("#02").html(board[2]);

	$("#10").html(board[3]);
	$("#11").html(board[4]);
	$("#12").html(board[5]);

	$("#20").html(board[6]);
	$("#21").html(board[7]);
    $("#22").html(board[8]);
}



$(document).ready(function(){
	$.get("/init", {}, function (response){
	
		var data = JSON.parse(response);

		var board = data["board"];

		updateBoard(board);

		$("#00").click(function(){
			var location = {"x": 0, "y": 0};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

                var board = data["board"];
                var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }

			});
		});

		$("#01").click(function(){
			var location = {"x": 0, "y": 1};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

                var board = data["board"];
				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});

		$("#02").click(function(){
			var location = {"x": 0, "y": 2};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

				var board = data["board"];

				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});


		$("#10").click(function(){
			var location = {"x": 1, "y": 0};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

				var board = data["board"];

				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});
		
		$("#11").click(function(){
			var location = {"x": 1, "y": 1};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

				var board = data["board"];

				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});

		$("#12").click(function(){
			var location = {"x": 1, "y": 2};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

				var board = data["board"];

				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});

		$("#20").click(function(){
			var location = {"x": 2, "y": 0};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

				var board = data["board"];

				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});

		$("#21").click(function(){
			var location = {"x": 2, "y": 1};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

				var board = data["board"];

				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});

		$("#22").click(function(){
			var location = {"x": 2, "y": 2};
			$.get("/click", location, function(response){
				var data = JSON.parse(response);

				var board = data["board"];

				var winner = data["winner"];

                updateBoard(board);
                
                if(winner != 0){
                    startOver(board);
                }
			});
		});

	});
});

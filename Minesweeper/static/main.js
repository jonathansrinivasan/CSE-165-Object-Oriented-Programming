function createGrid(data){
	var result = "";

	for (var i in data){
		var cr = "<tr>";

		for (var j in data[i]){
			cr = cr + "<td id=\"" + i.toString()+ "-" + j.toString() + "\"><button>"+i.toString()+ "-" + j.toString()+"</button></td>";
		}

		cr = cr + "</tr>\n";
		result = result + cr;
	}

	$("#grid").html(result);
}

function reset(){
	var board = [[0,0,0,0,0,0,0,0,0], 
					[0,0,0,0,0,0,0,0,0], 
					[0,0,0,0,0,0,0,0,0], 
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0]];
	createGrid(board);
	updateBoard(board, board, board);
}

function updateBoard(board, open_board, flag_board, won_game, lost_game){
	if(won_game == true){
		alert("You Won!");
	}

	for(var i in open_board){
		for(var j in open_board[i]){
			var theID = "#" + i.toString()+ "-" + j.toString();
			if(open_board[i][j] == true){
				if(flag_board[i][j] == true){
					$(theID).html('<img src="flag.jpg" style="width:100px; height:100px">');
				}else if(board[i][j] == -1){
					$(theID).html('<img src="bomb.jpg" style="width:100px; height:100px">');
					alert("Game Over");
					//reset();
				}else if(board[i][j] == 0){
					$(theID).html('<img src="0.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 1){
					$(theID).html('<img src="1.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 2){
					$(theID).html('<img src="2.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 3){
					$(theID).html('<img src="3.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 4){
					$(theID).html('<img src="4.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 5){
					$(theID).html('<img src="5.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 6){
					$(theID).html('<img src="6.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 7){
					$(theID).html('<img src="7.png" style="width:100px; height:100px">');
				}else if(board[i][j] == 8){
					$(theID).html('<img src="8.png" style="width:100px; height:100px">');
				}else{
					$(theID).html("*");
				}

			}else{
				if(flag_board[i][j] == true){
					$(theID).html('<img src="flag.jpg" style="width:100px; height:100px">');
				}else{
					$(theID).html('<img src="tile.png" style="width:100px; height:100px">');
				}	
			}
		}
	}
}


$(document).ready(function(){
	var board = [[0,0,0,0,0,0,0,0,0], 
					[0,0,0,0,0,0,0,0,0], 
					[0,0,0,0,0,0,0,0,0], 
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0],
					[0,0,0,0,0,0,0,0,0]];
	createGrid(board);
	updateBoard(board, board, board, false, false);

	$.get('/init', {}, function(response){
		for (var i in board){
			for (var j in board[i]){
				var theID = "#" + i.toString()+ "-" + j.toString();

				$(theID).click({row: i, col: j}, function(e){
					var x = e.data.row;
					var y = e.data.col;
					//alert("Left Clicked on a square (" + x + ", " + y + ")");
	
					$.get('/handle', {"x": x, "y": y, "btn": "left"}, function(response){
                        var data = JSON.parse(response);
                        var board = data["board"];
                        var open_board = data["open_board"];
						var flag_board = data["flag_board"];
						
						updateBoard(board, open_board, flag_board);
						//alert("Handled square (" + x + ", " + y + ") :" + open_board[x][y]);
                    });
				});
				
				$(theID).contextmenu({row: i, col: j}, function(e){
					e.preventDefault();
                    var x = e.data.row;
                    var y = e.data.col;
                    $.get('/handle', {"x": x, "y": y, "btn": "right"}, function(response){
                        var data = JSON.parse(response);
                        var board = data["board"];
                        var open_board = data["open_board"];
						var flag_board = data["flag_board"];
						var won_game = result["won_game"];
						var lost_game = result["lost_game"];
						
						updateBoard(board, open_board, flag_board, won_game, lost_game);
						//alert("Handled square (" + x + ", " + y + ") :" + flag_board[x][y]);
                    });
                });


			}
		}

	});
	
	//createGrid(board1);
});

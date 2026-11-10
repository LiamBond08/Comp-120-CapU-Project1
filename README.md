# Comp-120-CapU-Project1


The project consists of a game of tic-tac-toe with you, the player, playing against a computer. The player uses 'O' to identify themself in the game, while the computer uses 'X' to identify itself. The player will go first, and the computer will choose an empty spot at random by using rand() % 9, which makes for a pretty dumb computer, but I digress.

The tic-tac-toe board uses a 1D character array with 9 array elements. available squares are displayed as 0-8, and the player must type the number they want to occupy in order for the game to continue. Occupied squares contain a space character.   Un-occupied squares are given the character constant "Empty" and once a move is made by either the computer or the player, the character constant Empty will be applied to that square, this insures that the computer or player doesn't choose an already occupied square. 
  I used a do while loop to ensure that it will randomly check a square for occupancy and only stop the loop when it has found a square that in un-occupied.

My code uses an array of all possible win scenarios and checks, after each move, if any of the winning patterns are true and checks if all three squares contain the players symbol or the computers symbol, then if the player wins the function will return true which will cause "Congratulations! You Win!" to be printed and game_over will be set equal to true.
  Once game_over = true the player will be prompted with "Play again? (y = yes, q = quit)" if the players types y then the game will restart, and if the player types q then the game will quit.

  After each move the function, other_player, runs and it uses an if statement to check if the player is the human or the computer. If player == Human then it will return Computer; and if the if statement isn't met, then it will return Human.

This is a project about the game of Reversi, which is divided into two modes: human vs. human and human vs. computer. 
It offers several different AI options for testing.

Here are some basic information about the interesting game:
1、Game Setup  
- Othello is played on an 8×8 board.  
- Each player takes turns placing discs. One player uses black discs, and the other uses white discs.  
- The game starts with four discs in the center: two black and two white, arranged diagonally.  

2、How to Play
1. Placing a Disc 
   - Players take turns placing one disc of their color on the board.  
   - A move must "sandwich" one or more of the opponent's discs between the placed disc and another of the player's own color.  
   - The sandwiched discs are then flipped to the current player's color.  

2. Valid Moves
   - A move is only valid if at least one opponent’s disc is flipped.  
   - You can capture in multiple directions: horizontally, vertically, or diagonally.  
   - If a player has no valid move, they must **pass** their turn.  

3. Flipping Discs  
   - When a valid move is made, all opponent's discs between the placed disc and an existing disc of the same color are flipped to the player's color.  

4. Game End  
   - The game ends when neither player can make a valid move (usually when the board is full).  
   - The player with the most discs of their color on the board wins.  

3、Additional Rules
- If both players cannot make a move, the game ends immediately.  
- In case of a tie (equal number of discs), the game is considered a draw.  

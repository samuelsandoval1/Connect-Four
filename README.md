# Lab 11
At this stage, you're starting to see many common patterns in coding. `for` loops to iterate over individual items in an array, `while` loops to try things repeatedly until a desired result is achieved, `if`/`else` to decide what to do, creating functions for repeated code. Very often, especially when developing software, you will be taking existing code and modifying it to do something else to create a completely different program.

In this lab, you will be modifying your tic tac toe code into a different game: Connect Four

## Connect Four
[Connect Four](https://en.wikipedia.org/wiki/Connect_Four) (also known as Captain's Mistress, Four Up, Plot Four, Find Four, Four in a Row, Four in a Line, Drop Four, and Gravitrips (in Soviet Union)) is a two-player connection game in which the players first choose a color and then take turns dropping one colored disc from the top into a seven-column, six-row vertically suspended grid. The pieces fall straight down, occupying the lowest available space within the column. The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs.

Rules:
* The board has 7 columns and 6 rows
* 2 players take turns "dropping" 1 pieces each turn into any column of their choosing with an available row
* Pieces "dropped" into a column must occupy the bottom-most available row.
* A column that is full cannot have more pieces dropped in.
* The first player to connect a straight line of 4, either horizontally, vertically, or diagonally, wins the game

## Objectives
* Gain programming and problem solving independence with fewer hints and less starter code
* Learn to recognize and reuse common patterns in programming
* Modify existing code to perform new tasks from the same fundamentals

## Instructions
Because this game is very similar to tic tac toe, it is reasonable to use your code from lab 10 as a starting point to copy from, and modifying it to play Connect Four instead:
* Use 6 rows x 7 columns instead of 3 rows x 3 columns for the board
* Modify all functions to accommodate the new board size
* Modify the function to get the player's moves to take just the desired column
* Modify the function to get the computer's moves to just choose a column that still has space left
* Implement some sort of detection for the bottom-most available row in any given column
* Modify the game winner detection function to check all directions for 4 in a row
  * Hint: Watch out for the borders! e.g. the leftmost border has no columns to the left
  * Hint: One approach is always to check all rows and all columns for potential wins, but this can be slow. An optimization is only to check the last move that was made to see if it created a 4 in a row.

To print the board clearly, have your `Print` function to display "boundaries" between the columns, using `|`

An empty board:
```
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | | | | |
```

As pieces begin to fill the board, it should look something like
```
| | | | | | | |
| | | | | | | |
| | | | | | | |
| | | | |o| | |
| | | |o|x| | |
|x| |o|x|x| | |
```
### Test Cases
1. When "dropping" a piece into a column, ensure it goes all the way "down" into the lowest unoccupied spot
2. Attempt to drop a piece into a column that is already full. The user should be prompted to select a different column.
3. Play the computer to a win (since it is moving randomly, this should not be hard). Ensure the game ends and the user is displayed as the winner.
4. Play the computer to a loss (this can be tricky if the computer is moving randomly, but can be bypassed by always forcing the computer to choose the same column) and ensure the computer is displayed as the winner.
5. Play to a draw. Ensure the game is displayed as such.


## Grading
* (1 point): Your code uses a function to print the board's rows and columns correctly after each of the player's and computer's moves
* (1 point): Your code uses a function that allows the user only to select valid columns (columns that still have available rows)
* (1 point): Your code correctly "drops" a piece to the bottom-most available row of a specified column
* (1 point): Your code uses a function to decide/play the computer's moves
* (1 point): Your code for the computer's move chooses only columns that have available rows
* (1 point): Your code correctly displays the computer's move as having "dropped" to the bottom of the computer's selected column
* (1 point): Your code alternates between the player's and computer's moves automatically
* (1 point): Your code uses a function to check the state of the game (player wins, computer wins, draw, or not finished)
* (1 point): Your code outputs the result of the game immediately upon a winner being identified or a draw occurring
* (1 point): Your code disallows further play upon game over
* (1 point extra credit): Your code uses any sort of AI to guide the computer's moves more intelligently other than random moves. For strategies, refer to https://www.wikihow.com/Win-at-Connect-4, or feel free to use your own.

# Snake-and-Ladder-project
PROBLEM STATEMENT

SNAKE AND LADDER:

The traditional Indian game is to be implemented with a predefined board matrix. 
Simulate it as a 2-player game with dice being rolled alternatively by the players. 
Place the player counter based on the number obtained. 
If the counter lands at the bottom of a ladder, you can move up to the top of the ladder. 
If the counter lands on the head of a snake, you must slide down to the bottom of the snake. 
The player who reaches the target first is the winner. 
The game of snake and ladder has many versions, we have chosen one of the classic versions below and implemented it.

RULES OF THE GAME:

Each player should roll one die to see who gets the highest number.
Whoever rolls the highest number gets to take the first turn.
The player get to chose a board of his/her choice. The player can decide the number of snakes and ladders. 
The player also gets to decide the position of each snake and ladder.
A default board is available too.
If two or more people roll the same number, and it is the highest number rolled, each of those people roll the die an additional time to see who gets to go first.
Players take turns to roll a dice and move along the number of squares rolled.
If a player lands on a square which has the base of a ladder upon it then he will move up to the top of the ladder.
If he lands on a square which has the head of a snake upon it then he will move down to the tail of the snake.
If a player reaches a position beyond the last square on the board, the player reaches the end and rolls back by remaining positions.
If a six was rolled, the player gets another chance to roll.
The first person to reach the highest square on the board wins.

DATA STRUCTURE:

One dimensional array
The indices are considered as a square on the board. The value of the array at each position indicates the square the player would reach if the player lands on that index.
1D array is space efficient against the 2D array. 
Though expressing the logic of the game in a 1D array is difficult, its implementation is easier than 2D array.

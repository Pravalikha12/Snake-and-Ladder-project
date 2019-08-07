# Snake-and-Ladder-project
#### PROBLEM STATEMENT

#### SNAKE AND LADDER:

###### The traditional Indian game is to be implemented with a predefined board matrix. 
###### Simulate it as a 2-player game with dice being rolled alternatively by the players. 
###### Place the player counter based on the number obtained. 
###### If the counter lands at the bottom of a ladder, you can move up to the top of the ladder. 
###### If the counter lands on the head of a snake, you must slide down to the bottom of the snake. 
###### The player who reaches the target first is the winner. 
###### The game of snake and ladder has many versions, we have chosen one of the classic versions below and implemented it.

#### RULES OF THE GAME:

###### Each player should roll one die to see who gets the highest number.
###### Whoever rolls the highest number gets to take the first turn.
###### The player get to chose a board of his/her choice. The player can decide the number of snakes and ladders. 
###### The player also gets to decide the position of each snake and ladder.
###### A default board is available too.
###### If two or more people roll the same number, and it is the highest number rolled, each of those people roll the die an additional time to see who gets to go first.
###### Players take turns to roll a dice and move along the number of squares rolled.
###### If a player lands on a square which has the base of a ladder upon it then he will move up to the top of the ladder.
###### If he lands on a square which has the head of a snake upon it then he will move down to the tail of the snake.
###### If a player reaches a position beyond the last square on the board, the player reaches the end and rolls back by remaining positions.
###### If a six was rolled, the player gets another chance to roll.
###### The first person to reach the highest square on the board wins.

#### DATA STRUCTURE:

###### One dimensional array
###### The indices are considered as a square on the board. The value of the array at each position indicates the square the player would reach if the player lands on that index.
###### 1D array is space efficient against the 2D array. 
###### Though expressing the logic of the game in a 1D array is difficult, its implementation is easier than 2D array.

#### IMAGES:

###### 1. MENU PAGE 

![MENU PAGE](imagesFolder/menu.png?raw=true "MENU PAGE")

###### 2. ADMIN BOARD

![REFERENCE BOARD](imagesFolder/referenceBoard.png?raw=true "REFERENCE BOARD")

![ADMIN BOARD](imagesFolder/adminBoard.png?raw=true "ADMIN BOARD")

###### 3.  USER GIVING THE BOARD DIMENSIONS AND DETAILS

![BOARD DIMENSIONS](imagesFolder/boardDimensions.png?raw=true "BOARD DIMENSIONS")

###### 4. 
###### [A] DECISION OF WHO GETS TO PLAY FIRST

![DECISION OF WHO GETS TO PLAY FIRST](imagesFolder/chooseFirstPlayer.png?raw=true "DECISION OF WHO GETS TO PLAY FIRST")

###### [B] BOARD STATUS

![BOARD STATUS](imagesFolder/boardStatus.png?raw=true "BOARD STATUS")

###### 5. NEXT PLAYER'S TURN

![NEXT PLAYER'S TURN](imagesFolder/nextPlayerTurn.png?raw=true "NEXT PLAYER'S TURN")

###### 6.  
###### [A] PLAYER B's INITIAL POSITION

![PLAYER B's INITIAL POSITION](imagesFolder/playerPositionBeforeMove.png?raw=true "PLAYER B's INITIAL POSITION")

###### [B] AFTER FINDING A LADDER AT POSITION 22

![AFTER FINDING A LADDER AT POSITION 22](imagesFolder/playerPositionAfterMove.png?raw=true "AFTER FINDING A LADDER AT POSITION 22")

###### 7. 
###### [A] PLAYER B's INITIAL POSITION

![PLAYER B's INITIAL POSITION](imagesFolder/positionBeforeRollBack.png?raw=true "PLAYER B's INITIAL POSITION")

###### [B] AFTER REACHING THE END OF THE TABLE, PLAYER ROLLS BACK

![AFTER REACHING THE END OF THE TABLE, PLAYER ROLLS BACK](imagesFolder/positionAfterRollBack.png?raw=true "AFTER REACHING THE END OF THE TABLE, PLAYER ROLLS BACK")

###### 8. 
###### [A] PLAYER B's INITIAL POSITION

![PLAYER B's INITIAL POSITION](imagesFolder/positionBeforeSnake.png?raw=true "PLAYER B's INITIAL POSITION")

###### [B] AFTER FACING A SNAKE AT 47

![AFTER FACING A SNAKE AT 47](imagesFolder/positionAfterSnake.png?raw=true "AFTER FACING A SNAKE AT 47")

###### 9. EXTRA CHANCE, WHEN A SIX IS ROLLED

![EXTRA CHANCE, WHEN A SIX IS ROLLED](imagesFolder/sixIsRolled.png?raw=true "EXTRA CHANCE, WHEN A SIX IS ROLLED")

###### 10. A PLAYER WINS ONLY BY REACHING THE END OF THE BOARD, ROLLING AN EXACT VALUE TO THE END [IF ROLLED MORE THAN THAT PLAYER ROLLS BACK]

![GAME ENDS](imagesFolder/gameEnds.png?raw=true "GAME ENDS")

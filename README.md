# Max-Connect-4
An AI agent that plays the Max-Connect4 game using search. We dare you to win our agent.

## Game Rules
There are 7 columns in total, in which each has a height of 6. Two players take turn to drop their pieces into the columns. At each turn, the player can only drop one piece in any of the column. The game ends when all the columns are filled up. The winner is the one who has the higher count of the connecting 4 pieces on the board, either vertical, horizontal, or diagonal.

## Example Game
![](http://omega.uta.edu/~gopikrishnav/classes/2018/spring/4308_5360/assmts/assmt4_files/game.gif)

## Implementation
We use the Alpha-Beta-Prune Algorithm to implement our AI agent.

## How to run game
```
java maxconnect4 interactive [input_file] [computer-next/human-next] [depth]
```

For example:
```
java maxconnect4 interactive input1.txt computer-next 7
```

- Argument interactive specifies that the program runs in interactive mode.
- Argument [input_file] specifies an input file that contains an initial board state. This way we can start the program from a non-empty board state. If the input file does not exist, the program should just create an empty board state and start again from there.
- Argument [computer-first/human-first] specifies whether the computer should make the next move or the human.
- Argument [depth] specifies the number of moves in advance that the computer should consider while searching for its next move. In other words, this argument specifies the depth of the search tree. Essentially, this argument will control the time takes for the computer to make a move.

---------------------------------------------------
STUDENT INFORMATION
---------------------------------------------------

Name: Phuoc Do
UTA ID: 1001239680
Email: phuoc.do@mavs.uta.edu

---------------------------------------------------
PROGRAMMING LANGUAGE
---------------------------------------------------

C++

---------------------------------------------------
CODE STRUCTURE
---------------------------------------------------

The project is divided into small parts as below:
- State:
	Related Files: State.cpp State.hpp
	Purpose: A class that implements a structure 
		for the states of the game.
- AlphaBetaPrune:
	Related Files: AlphaBetaPrune.cpp AlphaBetaPrune.hpp
	Purpose: this is a class that contains the
		related functions to calculate
		the best next move.
- GameMode:
	Related Files: GameMode.cpp GameMode.hpp
	Purpose: This class automates the the two
		game modes specified the the assignment.
- main:
	Related Files: main.cpp
	Purpose: Take the input arguments and pass
		them to the GameMode object to run.

---------------------------------------------------
HOW TO RUN CODE
---------------------------------------------------

- The folder contains:
	.cpp files
	.hpp files
	Makefile
	readme.txt
	eval-explanation.txt
	CPU-runtime.txt
	input files: input1.txt, input2.txt
- Open Terminal at this folder. To compile, type:
	
	make

- To run INTERACTIVE mode:

	./maxconnect4 interactive [input_file] [computer-next/human-next] [depth]

- To run ONE-MOVE mode:

	./maxconnect4 one-move [input_file] [output_file] [depth]

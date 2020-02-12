The program converts a program written in simple and restricted C language into a stream of tokens. These tokens are classified as keywords, operators(assignop, arithop, relop, punctuation), identifier, integer and floating point numbers.

A1.cpp - 			Contains main function, classes for token and symbol table
get_type.cpp - 		Contains function to get token type from lexeme, DFA implementation
get_type.h - 		Header file for get_type.cpp
Makefile - 			For compilation, running and cleaning the object files
input.txt - 		Input file having C program
Screenshot.png - 	Screenshot of output

To compile the program(in Linux):
make
To run the program:
make run
To clean the object/executable files
make clean

If system doesn't support makefile:
To compile:
g++ get_type.cpp A2.cpp -o A2.out
To run:
./A2.out

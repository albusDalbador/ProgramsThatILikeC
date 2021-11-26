// #include <stdbool.h>

#ifndef _INIT_BOARD_
#define _INIT_BOARD_


#define BOARD_SIZE 10

char ** initBoard();

void printBoard(char **);

int checkIfValid(int, int);

int checkIfFreeToPlace(int , int, char **);

#endif
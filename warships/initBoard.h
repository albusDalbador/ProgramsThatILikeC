// #include <stdbool.h>

#ifndef _INIT_BOARD_
#define _INIT_BOARD_


#define BOARD_SIZE 10

char ** initBoard();

void printBoard(char **);

int checkIfValid(int, int);

int checkIfFreeToPlace(int , int, char **);

int checkIfValid(int,int);

int chooseDirection(int,int);

int *generateField(char **);

void addOneDeckShip(char **);

void addTwoDeckShip(char **);

void addThreeDeckShip(char **);

void addFourDeckShip(char **);

void placeShips(char **);

void addSingleShip(char **,void (*)(char **));

#endif
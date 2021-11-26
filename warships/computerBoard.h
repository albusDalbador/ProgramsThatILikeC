#ifndef _COMPUTER_BOARD_H_
#define _COMPUTER_BOARD_H_

int chooseDirection(int,int);

int *generateField(char **);

void addOneDeckShip(char **);

void addTwoDeckShip(char **);

void addThreeDeckShip(char **);

void addFourDeckShip(char **);

void placeShips(char **);

void addSingleShip(char **,void (*)(char **));


#endif

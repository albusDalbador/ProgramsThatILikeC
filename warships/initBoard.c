#include "initBoard.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void addOneDeckShip(char **board) {
    int *field = generateField();

    board[field[0]][field[1]] = 'x';
}

void addSingleShip(char **board,void(*addFunction)(char **)) {
    addFunction(board);
}

int checkIfFree(int a, int b, char **board) {
    return !strcmp(board[a][b],"*");
}


int *generateField() {
    //add while loop here, to generate valid field
    int *field = (int)malloc(sizeof(int) * 2);

    srand(time(NULL));

    field[0] = rand() % 10;
    field[1] = rand() % 10;

    return field;
}


char  **initBoard() {
    char **result = malloc (BOARD_SIZE * sizeof(char *));

    for (int i = 0; i < BOARD_SIZE; i++) {
        result[i] = malloc(BOARD_SIZE * sizeof(char));
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            result[i][j] = '*';
        }
    }

    return result;
}

void placeShips(char **board) {

    void (*shipFunctions[])(char **) = {addOneDeckShip,addTwoDeckShip,addThreeDeckShip,addFourDeckShip};

    for (int i = 1; i <= 4; i++) {
        for (int j = i; j <= 4; j++) {
            addSingleShip(board,shipFunctions[j]);
        }
    }
}

void printBoard(char **board) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0 ; j < BOARD_SIZE; j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
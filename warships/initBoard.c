#include "initBoard.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int checkIfFreeToPlace(int a, int b, char **board) {
    // return board[a][b] == '*';

    for (int i = a - 1; i <= a+1; i++) {
        for (int j = b-1; j <= b+1; j++) {
            if (checkIfValid(i,j)) {
                if (board[i][j] != '*') {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int checkIfValid(int a, int b) {
    return a >=0 && a <= 9 && b >= 0 && b <= 9;
}


int *generateField(char **board) {
    int *field = (int *)malloc(sizeof(int) * 2);
    
    srand(time(NULL));

    field[0] = rand() % 10;
    field[1] = rand() % 10;
    
    while (!checkIfFreeToPlace(field[0],field[1],board))
    {
        
        field[0] = rand() % 10;
        field[1] = rand() % 10;
    }

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


void printBoard(char **board) {

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0 ; j < BOARD_SIZE; j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
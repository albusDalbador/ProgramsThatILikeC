#include "initComputerBoard.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void addFourDeckShip(char **board) {

}

void addThreeDeckShip(char **board) {

}

void addTwoDeckShip(char **board) {
    int *field = generateField(board);

    while (1)
    {
        if (checkIfFreeToPlace(field[0],field[1],board)) break;

        field = generateField(board);
    }
    

    int direction = chooseDirection(field[0],field[1]);

    int flag = 1;

    //    0
    //  3   1
    //    4
    // printf("%d\n",direction);
    while (flag) {
        switch (direction)
        {
        case 0:
            if (checkIfFreeToPlace(field[0] -1,field[1],board)) {
                board[field[0]-1][field[1]] = 'O';
                board[field[0]][field[1]] = 'O';
                return;
            } 
 
            break;

        case 1:
           if (checkIfFreeToPlace(field[0],field[1] + 1,board)) {
                board[field[0]][field[1] + 1] = 'O';
                board[field[0]][field[1]] = 'O';
                return;
            } 
            break;

        case 2:
            if (checkIfFreeToPlace(field[0] + 1,field[1],board)) {
                board[field[0] + 1][field[1]] = 'O';
                board[field[0]][field[1]] = 'O';
                return;
            } 
            break;

        case 3:
            if (checkIfFreeToPlace(field[0],field[1] - 1,board)) {
                board[field[0]][field[1] - 1] = 'O';
                board[field[0]][field[1]] = 'O';
                return;
            } 
            break;
        
        default:
            break;
        }
        // printf("%d\t %d\n",field[0],field[1]);

        direction = chooseDirection(field[0],field[1]);
    }

}

void addOneDeckShip(char **board) {

    int *field = generateField(board);

    board[field[0]][field[1]] = 'O';
}

void addSingleShip(char **board,void(*addFunction)(char **)) {
    
    addFunction(board);
}

int checkIfFreeToPlace(int a, int b, char **board) {
    // return board[a][b] == '*';

    for (int i = a - 1; i <+ a+1; i++) {
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

int chooseDirection(int a, int b) {

    srand(time(NULL));

    int direction = rand() % 4;

    return direction;
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

void placeShips(char **board) {

    void (*shipFunctions[])(char **) = {addOneDeckShip,addTwoDeckShip,addThreeDeckShip,addFourDeckShip};

    for (int i = 0; i < 4; i++) {
        // addSingleShip(board,shipFunctions[0]);
        for (int j = i; j < 4; j++) {
            addSingleShip(board,shipFunctions[i]);
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
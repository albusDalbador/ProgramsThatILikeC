#include <stdlib.h>
#include <time.h>
#include "computerBoard.h"

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

    while (1) {
        if (checkIfFreeToPlace(field[0],field[1],board)) break;

        field = generateField(board);
    }

    board[field[0]][field[1]] = 'O';
}

void addSingleShip(char **board,void(*addFunction)(char **)) {
    
    addFunction(board);
}


int chooseDirection(int a, int b) {

    srand(time(NULL));

    int direction = rand() % 4;

    return direction;
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

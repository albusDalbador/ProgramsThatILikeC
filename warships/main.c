#include <stdio.h>
#include "initBoard.h"
#include "playerBoard.h"
#include "computerBoard.h"


int main(int argc, char *argvp[]) {

    char *(*computerBoard)[BOARD_SIZE] = initBoard();

    placeShips(computerBoard);

    printBoard(computerBoard);

    char *(*playerBoard)[BOARD_SIZE] = initBoard();



    return 0;
}
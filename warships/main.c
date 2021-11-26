#include <stdio.h>
#include "initComputerBoard.h"


int main(int argc, char *argvp[]) {

    char *(*board)[BOARD_SIZE] = initBoard();

    placeShips(board);

    printBoard(board);

    return 0;
}
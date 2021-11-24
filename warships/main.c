#include <stdio.h>
#include "initBoard.h"


int main(int argc, char *argvp[]) {

    char *(*board)[BOARD_SIZE] = initBoard();

    placeShips(board);

    printBoard(board);

    return 0;
}
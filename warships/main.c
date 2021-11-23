#include <stdio.h>
#include "initBoard.h"


int main(int argc, char *argvp[]) {

    char *(*board)[BOARD_SIZE] = initBoard();

    printBoard(board);

    return 0;
}
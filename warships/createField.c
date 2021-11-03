#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define FIELD_SIZE 10

int *generateRandomField();
bool checkIfValid(int,int);
bool checkIfFree(int*,char **);
char **allocateField();
void clearMemField(char**);
// void fillWithZeroes(int**);
void printField(int **);

int main(int argc, char *argv[]) {

    char **field = allocateField();
    fillWithZeroes(field);
    printField(field);
    

    clearMemField(field);
    return 0;
}

void printField(int **field) {
    for (int i =0; i < FIELD_SIZE; i++) {
        for (int j =0 ; j < FIELD_SIZE; j++) {
            printf("%d  ",field[i][j]);
        }
        printf("\n");
    }
}

int *generateRandomSquare(int **field) {
    int *square = (int*)(sizeof(int)*2);

    srand(time(NULL));

    square[0] = (int)rand()%10;
    square[1] = (int)rand()%10;

    while (!checkIfFree(square, field)) {
        square[0] = (int)rand()%10;
        square[1] = (int)rand()%10;
    }

    return square;

}

bool checkIfFree(int *square, char **field) {

    for (int x = square[0] - 1; x <= square[0] + 1; x++ ) {

        for (int y = square[1] -1; y <= square[1] +1; y++) {

            if (checkIfValid(x,y)) {
                if (field[x][y] != '.') return false;
            }
        }
    }

    return true;
}

bool checkIfValid(int x, int y) {
    return x >=0 && x <= 9 && y <=9 && y >= 0;
}

char **allocateField() {
    char  **result = (int**)malloc(FIELD_SIZE*sizeof(int*));

    for (int i = 0 ; i < FIELD_SIZE; i++) {
        result[i] = (int*)malloc(FIELD_SIZE* sizeof(int));
    }

    return result;
}

void clearMemField(char **arr) {
    for (int i = 0 ; i < FIELD_SIZE; i++) {
        free(arr[i]);
    }

    free(arr);

    return;
}

// void fillWithZeroes (int **field) {
//     for (int i =0; i < FIELD_SIZE; i++) {
//         for (int j =0 ; j < FIELD_SIZE; j++) {
//             field[i][j] =0;
//         }
//     }
//     // memset(field,0,sizeof(int)*FIELD_SIZE*FIELD_SIZE);
// }
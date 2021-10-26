#include <stdio.h>

void createPascalTriangle(int);
int getTheNumberByPos(int,int);

int main (int argc, char *argv[]) {

    printf("Give the number of lines\n");

    int n;

    scanf("%d",&n);

    // printf("%d\n",getTheNumberByPos(6,3));
    createPascalTriangle(n);

    return 0;
}

void createPascalTriangle(int n) {

    for (int line = 1 ; line <= n; line++) {
            
        for (int row = 1; row <= line; row++) {
        
            printf("%d\t",getTheNumberByPos(line,row));
        
        }
        
        printf("\n");
    }
}

int getTheNumberByPos(int line, int row) {

    if (line == 1) return 1;

    if (row == 1 || row == line ) return 1;

    else return getTheNumberByPos(line-1,row) + getTheNumberByPos(line - 1,row -1);
}
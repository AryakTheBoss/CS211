#include <stdio.h>
#include <stdlib.h>

int ** multiplyArrays(int ** matrixA, int ** matrixB, int ** resMatrix, int rows, int cols, int row1);
void printArray(int ** matrix, int rows, int cols);
void freeArray(int ** matrix, int rows);
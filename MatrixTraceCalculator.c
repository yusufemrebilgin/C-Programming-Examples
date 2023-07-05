#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int, int);
void fillMatrix(int **, int, int);
int calculateTrace(int **,int);
void printMatrix(int **, int, int);
void freeMatrix(int **, int);

int main(void){

    int row, col;
    printf("Enter matrix size:\n");
    printf("Row: "); scanf("%d", &row);
    printf("Col: "); scanf("%d", &col);
    if (row != col){
        fprintf(stderr, "Not a square matrix");
        exit(EXIT_FAILURE);
    }

    int **matrix = createMatrix(row,col);
    fillMatrix(matrix, row, col);

    printf("\n\nGiven Matrix:\n");
    printMatrix(matrix, row, col);

    printf("\n\nTrace: %d\n", calculateTrace(matrix,row));

    freeMatrix(matrix,row);

    return 0;
}
int **createMatrix(int row, int col){
    
    int i, j, **matrix = (int **)malloc(sizeof(int*) * row);
    if (matrix == NULL){
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (i=0 ; i < row ; i++){
        matrix[i] = (int *)malloc(sizeof(int) * col);
        if (matrix[i] == NULL){
            fprintf(stderr, "Memory allocation failed");
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}
void fillMatrix(int **matrix, int row, int col){
    int i, j;
    for (i=0 ; i < row ; i++)
        for (j=0 ; j < col ; j++){
            printf("Enter [%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
}
int calculateTrace(int **matrix, int size){
    int i, trace = 0;
    for (i=0 ; i < size ; i++)
        trace += matrix[i][i];

    return trace;
}
void printMatrix(int **matrix, int row, int col){
    int i, j;
    for (i=0 ; i<row ; i++){
        for (j=0 ; j<col ; j++)
            printf("%-3d ", matrix[i][j]);
        printf("\n");
    }
}
void freeMatrix(int **matrix, int row){
    int i;
    for (i = 0 ; i < row ; i++)
        free(matrix[i]);
    free(matrix);
}
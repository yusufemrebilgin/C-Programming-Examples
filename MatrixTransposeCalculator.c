#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int, int);
void fillMatrix(int **, int , int);
int **calculateTranspose(int **, int, int);
void printMatrix(int **, int, int);
void freeMatrix(int **, int);

int main(void){

    int row, col;
    printf("Enter matrix size:\n");
    printf("Row: "); scanf("%d", &row);
    printf("Col: "); scanf("%d", &col);

    int **matrix = createMatrix(row,col);
    fillMatrix(matrix, row, col);

    printf("\n\nGiven Matrix:\n");
    printMatrix(matrix, row, col);

    int **solution = calculateTranspose(matrix, row, col);
    printf("\n\nSolution:\n");
    printMatrix(solution, col, row);

    freeMatrix(matrix,row);
    freeMatrix(solution,col);

    return 0;
}
int **createMatrix(int row, int col){
    
    int i, j, **matrix = (int **)malloc(sizeof(int*) * row);
    if (matrix == NULL){
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (i=0 ; i < row ; i++){
        matrix[i] = (int *)malloc(sizeof(int) * col);
        if (matrix[i] == NULL){
            fprintf(stderr, "Error: Memory allocation failed\n");
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
int **calculateTranspose(int **matrix, int row, int col){
    int i, j, **transpose = createMatrix(col,row);

    for (i=0 ; i < row ; i++)
        for (j=0 ; j < col ; j++)
            transpose[j][i] = matrix[i][j];
    
    return transpose;
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
    for (i=0 ; i < row ; i++)
        free(matrix[i]);
    free(matrix);
}
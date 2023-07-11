#include <stdio.h>
#include <stdlib.h>

double factorial(int);  

int main(void){

    int i, j, k, row, space;

    printf("Enter row number: ");
    scanf("%d", &row);

    double *p = malloc(sizeof(double) * (row * (row+1) / 2));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (i = 0, k = 0 ; i < row ; ++i)
        for (j = 0 ; j <= i ; ++j)
            p[k++] = factorial(i) / (factorial(j) * factorial(i-j));
    
    space = row;
    for (i = 0, k = 0 ; i < row ; ++i, --space) {
        for (j = 0 ; j < space ; ++j)
            printf("    ");
        for (j = 0 ; j <= i ; ++j)
            printf("%8.0lf", p[k++]);
        printf("\n");
    }

    free(p);

    return 0;
}
double factorial(int num){
    double result = 1.0;
    while (num > 1) {
        result *= num--;
    }
    return result;
}
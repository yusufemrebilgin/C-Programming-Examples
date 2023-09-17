#include <stdio.h>

int main(void){

    int i, j, row;

    printf("Enter row number: ");
    scanf("%d", &row);

    int space = row;

    for (i = 0; i < row; i++) {

        for (j = space - 1; j != 0; j--)
            printf(" ");

        for (j = 0; j <= i; j++)
            printf("%c", 'A' + j);

        for (j = i - 1; j >= 0; j--)
            printf("%c", 'A' + j);

        printf("\n");
        space--;
    }

    return 0;
}
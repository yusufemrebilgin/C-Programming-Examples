#include <stdio.h>

int countDigit(int);

int main(void){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    printf("%d digit(s)\n", countDigit(number));

    return 0;
}
int countDigit(int num){
    return (num != 0) ? (1 + countDigit(num / 10)) : 0 ;
}
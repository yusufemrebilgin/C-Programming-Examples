#include <stdio.h>

int recursiveGCD(int, int);

int main(void){

    int num1, num2;
    printf("Please enter first number:  "); scanf("%d", &num1);
    printf("Please enter second number: "); scanf("%d", &num2);

    printf("GCD(%d,%d): %d\n", num1, num2, recursiveGCD(num1,num2));

    return 0;
}
int recursiveGCD(int x, int y){
    if (y == 0)
        return x;
    else
        return recursiveGCD(y, x%y);
}
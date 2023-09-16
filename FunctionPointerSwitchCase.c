#include <stdio.h>

void addition(int x, int y){
    printf("Result: %d\n", x + y);
}
void substraction(int x, int y){
    printf("Result: %d\n", x - y);
}
void multiplication(int x, int y){
    printf("Result: %d\n", x * y);
}
void division(int x, int y){
    printf("Result: %.2lf\n", (double)x / y);
}

int main(void){

    void (*functionPtr[])(int,int) = {addition, substraction, multiplication, division};

    int num1, num2, choice;
    printf("Enter first number:  ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\nAddition          [1]");
    printf("\nSubstraction      [2]");
    printf("\nMultiplication    [3]");
    printf("\nDivision          [4]");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    functionPtr[choice - 1](num1, num2);

    return 0;
}
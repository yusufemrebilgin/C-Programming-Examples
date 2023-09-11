#include <stdio.h>
#include <stdbool.h>

bool isStrongNumber(int num);
int factorial(int num);

int main(void){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if (isStrongNumber(number))
        printf("%d is a strong number.\n", number);
    else
        printf("%d is not a strong number.\n", number);

    return 0;
}

bool isStrongNumber(int num){
    int sum = 0, temp = num;
    while (temp != 0) {
        sum += factorial(temp % 10);
        temp /= 10;
    }
    return (sum == num);
}
int factorial(int num){
    int result = 1;
    while (num > 1) {
        result *= num--;
    }
    return result;
}
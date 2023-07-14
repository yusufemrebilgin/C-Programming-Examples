#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isArmstrong(int);

int main(void){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number))
        printf("%d is an armstrong number.\n", number);
    else
        printf("%d is not an armstrong number.\n", number);

    return 0;
}

bool isArmstrong(int num){
    int sum = 0, digit = 0, temp = num;
    while (temp) {
        temp /= 10;
        digit++;
    }
    temp = num;
    while (temp) {
        sum += pow(temp % 10, digit);
        temp /= 10;   
    }

    if (sum == num) return true;
    else return false;
}
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main(void){

    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}

bool isPrime(int number){
    if (number < 2) return false;
    int i;
    for (i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}
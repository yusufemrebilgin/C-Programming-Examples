#include <stdio.h>
#include <stdbool.h>

bool isPrime(int);

int main(void){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if (isPrime(number))
        printf("%d is a prime number.\n", number);
    else
        printf("%d isn't a prime number.\n", number);

    return 0;
}
bool isPrime(int num){
    static int i = 2;
    if (i == num)
        return true;
    else if (num % i == 0 || num <= 1)
        return false;
    
    i += 1;
    isPrime(num);
}
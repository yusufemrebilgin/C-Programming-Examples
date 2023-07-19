#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int);

int main(void){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if (isPalindrome(number))
        printf("%d is a palindrome number.\n", number);
    else
        printf("%d is not a palindrome number.\n", number);

    return 0;
}

bool isPalindrome(int number){
    int reversedNumber = 0;
    int originalNumber = number;

    while (number) {
        reversedNumber = number % 10 + reversedNumber * 10;
        number /= 10;
    }
    
    return (originalNumber == reversedNumber);
}
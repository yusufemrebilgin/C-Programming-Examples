#include <stdio.h>
#include <stdbool.h>

bool isPerfect(int);

int main(void){

    int number;
    printf("Please enter a number: ");
    scanf("%d", &number);

    if (isPerfect(number))
        printf("%d is a perfect number.\n", number);
    else
        printf("%d is not a perfect number.\n", number);

    return 0;
}

bool isPerfect(int num){
    int i, sum = 0;
    for (i = 1 ; i != num ; ++i) 
        if (num % i == 0) sum += i;
    
    if (num == sum) 
        return true;
    return false;
}
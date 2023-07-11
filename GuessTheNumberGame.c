#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 100

int main(void){

    srand( time(NULL) );

    int guess;
    int number = rand() % LIMIT + 1;
    int numberOfGuess = 0;
    
    printf("Guess a number between 1 and %u:  ", LIMIT);
    while (1) {
        scanf("%d", &guess);
        ++numberOfGuess;
        if (guess == number){
            printf("Congratulations! You got the number in %d guesses.\n", numberOfGuess);
            break;
        }
        else if (guess > number)
            printf("Your guess is too high! Try again: ");
        else if (guess < number)
            printf("Your guess is too low! Try again:  ");
        
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int countPrimeNumbersUpTo(int n);

int main(void){

    int n;
    printf("Please enter a positive integer: ");
    scanf("%d", &n);

    printf("Number of primes (2 to %d): %d\n", n, countPrimeNumbersUpTo(n));

    return 0;
}

int countPrimeNumbersUpTo(int n){

    bool *list = malloc(sizeof(bool) * (n + 1));
    memset(list, true, sizeof(bool) * (n + 1));

    int i, j, numberOfPrimes = 0;
    for (i = 2; i * i <= n; i++) {
        if (list[i] == true)
            for (j = 2; i * j <= n; j++)
                list[i * j] = false;
    }
    for (i = 2; i <= n; i++)
        if (list[i] == true)
            numberOfPrimes++;

    free(list);
    
    return numberOfPrimes;
}
#include <stdio.h>

int fibonacci(int);

int main(void){

    int n;
    printf("Enter term number: ");
    scanf("%d", &n);

    printf("Fibonacci(%d): %d\n", n, fibonacci(n));

    return 0;
}
int fibonacci(int n){
    return (n == 0 || n == 1) ? n : fibonacci(n-1) + fibonacci(n-2);
}
#include <stdio.h>
#include <stdarg.h>

double calculateAverage(int numOfElements, ...){
    int i;
    int sum = 0;

    va_list args;
    va_start(args, numOfElements);

    for (i = 0; i < numOfElements; i++) {
        sum += va_arg(args, int);
    }

    va_end(args);
    
    return (double)sum / numOfElements;
}

int main(void){

    printf("%.2lf\n", calculateAverage(3, 84, 66, 55));

    return 0;
}
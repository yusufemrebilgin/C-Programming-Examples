#include <stdio.h>
#include <time.h>

void withRegisterVariable(int n){
    register double i;
    clock_t start = clock();
    for (i = 0.0; i < n; i += 0.0001) continue;
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Running time is %lf second with register variable\n", time);
}

void withoutRegisterVariable(int n){
    double i;
    clock_t start = clock();
    for (i = 0.0; i < n; i += 0.0001) continue;
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Running time is %lf second without register variable\n", time);
}

int main(void){

    int n = 100000;
    
    withRegisterVariable(n);
    withoutRegisterVariable(n);
    
    return 0;
}
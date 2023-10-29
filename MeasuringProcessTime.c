#include <stdio.h>
#include <time.h>

int main(void){

    printf("Press [enter] to stop..");

    clock_t start = clock();
    
    while (getchar() != '\n')
        continue;

    clock_t end = clock();

    double time = (double) (end - start) / CLOCKS_PER_SEC;

    printf("Process time: %lf seconds\n", time);

    return 0;
}
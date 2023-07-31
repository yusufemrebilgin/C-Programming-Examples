#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    unsigned int i, numOfPoints;
    unsigned int pointsInCircle = 0;

    printf("Enter number of points: ");
    scanf("%u", &numOfPoints);

    srand(time(NULL));

    time_t start = clock();
    
    for (i = 0; i < numOfPoints; i++) {
        double coordX = (double) rand() / RAND_MAX;
        double coordY = (double) rand() / RAND_MAX;
        double distance = coordX * coordX + coordY * coordY;
        if (distance <= 1) 
            ++pointsInCircle;
    }

    time_t end = clock();
    
    double time = (double) (end - start) / CLOCKS_PER_SEC;
    double valueOfPI = 4.0 * pointsInCircle / numOfPoints;

    printf("PI Value: %f\n", valueOfPI);
    printf("CPU Time: %f seconds.\n", time);
    
    
    return 0;
}
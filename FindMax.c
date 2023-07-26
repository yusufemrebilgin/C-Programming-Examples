#include <stdio.h>
#include <stdlib.h>

int *findMax(const int *arr, int size);

int main(void){

    int i, size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int *array = (int *)malloc(sizeof(int) * size);

    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0 ; i < size ; i++) {
        printf("%d) ", i + 1);
        scanf("%d", &array[i]);
    }

    int *max = findMax(array, size);
    printf("Max number: %d\n", *max);

    free(array);

    return 0;
}

int *findMax(const int *arr, int size){
    int i, *max = (int *)arr;

    for (i = 0 ; i < size ; i++)
        if (*max < *(arr + i))
            *max = *(arr + i);

    return max;
}
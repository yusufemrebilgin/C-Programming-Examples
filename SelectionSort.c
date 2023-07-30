#include <stdio.h>

void selectionSort(int array[], int n);
void swap(int *x, int *y);
void printArray(int array[], int size);

int main(void){

    int arr[] = {34, 16, 72, 4, 86, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);
    printArray(arr, size);

    return 0;
}

void selectionSort(int array[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min_index = i;
        for (j = i + 1; j < n; j++)
            if (array[min_index] > array[j])
                min_index = j;
        
        swap(&array[min_index], &array[i]);
    }
}
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void printArray(int array[], int size){
    int i;
    for (i = 0; i < size ; i++)
        printf("%d ", array[i]);
    printf("\n");
}
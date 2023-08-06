#include <stdio.h>

void insertionSort(int array[], int n);
void printArray(int array[], int size);

int main(void){

    int arr[] = {36, 75, 12, 4, 5, 16, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}
void insertionSort(int array[], int n){
    int i, j, temp;
    for (i = 1; i < n; i++) {
        
        temp = array[i];
        j = i - 1;
        while (temp < array[j] && j >= 0){
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = temp;
    }
}
void printArray(int array[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}
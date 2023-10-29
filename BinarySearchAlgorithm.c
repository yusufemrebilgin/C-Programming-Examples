#include <stdio.h>

int binarySearch(int array[], int size, int target);

int main(void){

    int i, array[100];
    int size = sizeof(array) / sizeof(array[0]);
    
    for (i = 0; i < size; i++)
        array[i] = i * 10;

    for (i = 0; i < size; i++)
        printf("%d) %d\n", i, array[i]);

    int num = 770;

    printf("The number %d was found in the %d. place\n", num, binarySearch(array, size, num));

    return 0;
}

int binarySearch(int array[], int size, int target){
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] < target)
            left = mid + 1;
        else if (array[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}
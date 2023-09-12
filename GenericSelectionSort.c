#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpInteger(const void *a, const void *b);
int cmpFloat(const void *a, const void *b);
int cmpString(const void *a, const void *b);
void swap(void *var1, void *var2, size_t size);
void selectionSort(void *array, size_t arrLength, size_t size, int (*cmp)(const void *, const void *));
void printArray(const void *array, size_t arrSize, const char *format);

int main(void){

    int intArray[] = {34, 55, 61, 7, 88, 11};
    size_t intArrSize = sizeof(intArray) / sizeof(int);

    float floatArray[] = {3.55, 2.44, 3.34, 1.06, 1.77, 0.66};
    size_t floatArrSize = sizeof(floatArray) / sizeof(float);

    char *strArray[] = {"Istanbul", "Ankara", "Izmir", "Mugla", "Kocaeli"};
    size_t strArrSize = sizeof(strArray) / sizeof(char *);

    printf("Before Sorting:\n");
    printArray(intArray, intArrSize, "d");
    printArray(floatArray, floatArrSize, "f");
    printArray(strArray, strArrSize, "s");
    printf("\n");

    selectionSort(intArray, intArrSize, sizeof(int), cmpInteger);
    selectionSort(floatArray, floatArrSize, sizeof(float), cmpFloat);
    selectionSort(strArray, strArrSize, sizeof(char *), cmpString);

    printf("After Sorting:\n");
    printArray(intArray, intArrSize, "d");
    printArray(floatArray, floatArrSize, "f");
    printArray(strArray, strArrSize, "s");
    printf("\n");

    return 0;
}

int cmpInteger(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int cmpFloat(const void *a, const void *b){
    if (*(float *)a > *(float *)b)
        return 1;
    else if (*(float *)a < *(float *)b)
        return -1;
    else
        return 0;
}

int cmpString(const void *a, const void *b){
    return strcmp(*(char **)a, *(char **)b);
}

void swap(void *var1, void *var2, size_t size){
    char *temp = malloc(sizeof(char));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(temp, var1, size);
    memcpy(var1, var2, size);
    memcpy(var2, temp, size);
    free(temp);
}

void selectionSort(void *array, size_t arrLength, size_t size, int (*cmp)(const void *, const void *)){
    for (size_t i = 0; i < arrLength - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arrLength; j++) {
            if (cmp((char *)array + minIndex * size, (char *)array + j * size) > 0)
                minIndex = j;

        }
        if (minIndex != i)
            swap((char *)array + minIndex * size, (char *)array + i * size, size);
    }
}

void printArray(const void *array, size_t arrSize, const char *format){
    for (size_t i = 0; i < arrSize; i++) {
        if (!strcmp("d", format))
            printf("%d ", *((int *)array + i));
        if (!strcmp("f", format))
            printf("%.2f ", *((float *)array + i));
        if (!strcmp("s", format))
            printf("%s ", *((char **)array + i));
    }
    printf("\n");
}
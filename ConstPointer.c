#include <stdio.h>
/*
Pointer to Constant int: 
    const int *ptr
Constant Pointer to int: 
    int *const ptr
Constant Pointer to Constant int: 
    const int *const ptr
*/
void fun(const int *p){
    // *p = 5; // Hatalı Kod
}

int main(void){

    int arr[] = {2, 3, 4, 5, 6};
    
    int *const ptr = arr;
    *(ptr + 2) = 34;
    // 'Constant Pointer' olduğu için adresi değiştiremeyiz
    // ptr = NULL;  // Hata!

    const int *const p = arr;
    // p = NULL;    // Hata!
    // *p = 5;      // Hata!


    return 0;
}
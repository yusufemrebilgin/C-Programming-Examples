#include <stdio.h>

int main(void){

    //Getting a bit

    int n = 3;
    unsigned char x = 133;      //10000101
    char mask = 1;              //00000001
                                //00000100  (mask<<(n-1))
    
    if (x & mask<<(n-1))        //00000100
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
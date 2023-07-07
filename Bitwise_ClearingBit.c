#include <stdio.h>

int main(void){

    //Clearing a bit

    int n = 5;
    unsigned char x = 147;      //10010011
    char mask = 1;              //00000001
                                //00010000   (mask<<(n-1))

                                //10010011   (Decimal: 147)
                                //11101111  ~(mask<<4)
    x &= ~(mask<<(n-1));        //10000011   (Decimal: 131)  

    printf("%d\n", x);

    return 0;
}
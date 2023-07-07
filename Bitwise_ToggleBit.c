#include <stdio.h>

int main(void){

    //Toggling a bit

    int n = 6;
    unsigned char x = 163;      //10100011
    char mask = 1;              //00000001
    
                                //10100011
                                //00100000  (mask<<(n-1))
    x ^= mask<<(n-1);           //10000011  (Decimal: 131)
    printf("%d\n", x);

                                //10000011  (Decimal: 131)
                                //00100000  (mask<<(n-1))
    x ^= mask<<(n-1);           //10100011  (Decimal: 163)
    printf("%d\n", x);

    return 0;
}
#include <stdio.h>

int main(void){

    //Setting a bit

    int n = 4;
    unsigned char x = 131;      //10000011
    char mask = 1;              //00000001
                                //00001000  (mask<<(n-1))
    x |= mask<<(n-1);           //10001011  (Decimal: 139)

    printf("%d\n", x);

    return 0;
}
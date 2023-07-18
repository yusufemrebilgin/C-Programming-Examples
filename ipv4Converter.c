#include <stdio.h>

int main(void){

    int i;
    unsigned int ipv4 = 0xC3A80F02;
    unsigned int mask = 0xff000000;
    unsigned int temp, bit = 32;

    for (i = 1; i <= 4 ; i++) {

        temp = ipv4 & mask;
        if (i != 4) {
            temp >>= bit - i*8;
            printf("%d.", temp);
            mask >>= 8;
        } else
            printf("%d", temp);

    }

    return 0;
}
#include <stdio.h>
#include <math.h>

int binaryToDecimal(int binary);

int main(void){

    int number;
    printf("Enter binary number: ");
    scanf("%d", &number);
    
    printf("Decimal: %d\n", binaryToDecimal(number));

    return 0;
}

int binaryToDecimal(int binary){
    int i, decimal = 0;
    for (i = 0 ; binary != 0 ; i++){
        if (binary % 10 == 1)
            decimal += pow(2, i);
        binary /= 10;
    }

    return decimal;
}
#include <stdio.h>

int decimalToBinary(int decimal);

int main(void){

    int number;
    printf("Enter decimal number: ");
    scanf("%d", &number);
    
    printf("Binary: %d\n", decimalToBinary(number));

    return 0;
}

int decimalToBinary(int decimal){
    int i, binary = 0;
    int x = 1;
    for (i = 0 ; decimal != 0 ; i++) {
        binary += decimal % 2 * x;
        decimal /= 2;
        x *= 10;
    }
    return binary;
}
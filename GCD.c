//Öklid algoritması ile EBOB hesaplama
#include <stdio.h>

int GCD(int a, int b){
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void){

    int num1, num2;
    scanf("%d%d", &num1, &num2);

    printf("%d", GCD(num1,num2));

    return 0;
}
#include <stdio.h>
#include <string.h>

char *reverseString(char *str);

int main(void){

    char str[] = "C Programming Language";

    printf("%s\n", reverseString(str));

    return 0;
}

char *reverseString(char *str){
    size_t i, len;
    char temp;
    for (i = 0, len = strlen(str) ; i < len/2 ; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    str[len] = '\0';
    return str;
}
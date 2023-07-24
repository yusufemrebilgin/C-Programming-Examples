#include <stdio.h>

char *strcat(char *dest, const char *source);

int main(void){

    char str[20] = "abc";
    strcat(str, "xyz");

    printf("%s\n", str);
    
    return 0;
}

char *strcat(char *dest, const char *source){
    while (*dest != '\0')
        dest++;
    for ( ; (*dest = *source) ; dest++, source++);
    
    return dest;
}
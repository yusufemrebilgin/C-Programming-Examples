#include <stdio.h>

size_t strlen(const char *str);

int main(void){

    char str[] = "C Programlama Dili";

    printf("%zu\n", strlen(str));
    
    return 0;
}

size_t strlen(const char *str){
    size_t len = 0;
    
    for ( ; str[len] != '\0' ; ++len);
    return len;
}

/*
size_t strlen(const char *str){

    const char *s = str;

    for ( ; *s ; ++s);
    return (s - str);
}
*/
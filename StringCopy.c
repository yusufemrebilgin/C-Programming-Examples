#include <stdio.h>

char *strcpy(char *dest, const char *source);

int main(void){

    char dest[20];
    strcpy(dest, "Hello, World!");

    printf("%s\n", dest);
  
    return 0;
}

char *strcpy(char *dest, const char *source){
    
    for ( ; (*dest = *source) != '\0' ; ++dest, ++source);

    return dest;
}
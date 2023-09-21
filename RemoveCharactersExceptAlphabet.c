#include <stdio.h>
#include <ctype.h>

void removeChExceptAlphabet(char *text);

int main(void){
    
    char text[500];
    
    printf("Please enter a text: ");
    fgets(text, sizeof(text), stdin);

    removeChExceptAlphabet(text);

    printf("%s", text);
    
    return 0;
}

void removeChExceptAlphabet(char *text){
    int i, j;
    for (i = 0, j= 0; text[i] != '\0'; i++) {
        if (isalpha(text[i]))
            text[j++] = text[i];
    }
    text[j] = '\0';
}
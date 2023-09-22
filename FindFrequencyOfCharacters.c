#include <stdio.h>

#define SIZE 500

int main(void){

    char ch, text[SIZE];

    printf("Please enter text: ");
    
    int i = 0, freq[256] = {0};

    while ((ch = getchar()) != '\n' && i < SIZE - 1) {
        text[i++] = ch;
    }
    text[i] = '\0';

    for (i = 0; text[i] != '\0'; i++)
        freq[text[i]]++;

    for (i = 0; i < 256; i++) {
        if (freq[i] != 0)
            printf("'%c' --> %d\n", i, freq[i]);
    }
    
    return 0;
}
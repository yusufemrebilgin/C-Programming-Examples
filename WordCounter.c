#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TEXT_SIZE 250

int main(void){

    char text[TEXT_SIZE];
    int i, wordCount = 0;
    int inWord = 0;

    printf("Please enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            if (!inWord) {
                inWord = 1;
                wordCount++;
            }
        }
        else
            inWord = 0;
    }
    
    printf("Word Count: %d", wordCount);

    return 0;
}
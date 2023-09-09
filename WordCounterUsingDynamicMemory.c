#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){

    int i, wordCount = 0, inWord = 0;
    char ch, *text = NULL;
    size_t textSize = 0;

    if ((text = malloc(sizeof(char))) == NULL) {
        fprintf(stderr, "Initial memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Please enter text: ");
    while ((ch = getchar()) != '\n') {
        if ((text = realloc(text, sizeof(char) * (++textSize + 1))) == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            free(text);
            exit(EXIT_FAILURE);
        }
        else {
            text[textSize - 1] = ch;
        }
    }
    text[textSize] = '\0';

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

    free(text);

    return 0;
}
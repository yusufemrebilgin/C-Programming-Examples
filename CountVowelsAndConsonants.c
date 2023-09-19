#include <stdio.h>
#include <ctype.h>

int main(void) {
    
    char text[500];
    char vowels[] = {'A','a','E','e','I','i','O','o','U','u'};
    
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    int i, j, numOfVowels = 0, numOfConsonants = 0, numOfAlphabetic = 0;
    
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            for (j = 0; j < 10; j++) {
                if (text[i] == vowels[j])
                    numOfVowels++;
            }
            numOfAlphabetic++;
        }
    }

    numOfConsonants = numOfAlphabetic - numOfVowels;

    printf("Number of vowels: %d\n", numOfVowels);
    printf("Number of consonants: %d\n", numOfConsonants);
    
    return 0;
}
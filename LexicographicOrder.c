#include <stdio.h>
#include <string.h>

#define NUM_OF_WORDS    10
#define WORD_SIZE       20

void swap(char *s1, char *s2);

int main(void){

    int i, j;
    char words[NUM_OF_WORDS][WORD_SIZE];

    printf("Please enter %d words:\n", NUM_OF_WORDS);
    for (i = 0; i < NUM_OF_WORDS; i++) {
        fgets(words[i], WORD_SIZE, stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
    }
    printf("\n");

    for (i = 0; i < NUM_OF_WORDS - 1; i++) {
        int index = i;
        for (j = i + 1; j < NUM_OF_WORDS; j++) {
            if (strcmp(words[index], words[j]) > 0)
                index = j;

        }
        swap(words[index], words[i]);
    }

    printf("Lexicographic Order:\n");
    for (i = 0; i < NUM_OF_WORDS; i++)
        printf("%s\n", words[i]);


    return 0;
}
void swap(char *s1, char *s2){
    char temp[WORD_SIZE];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}
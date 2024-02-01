#include <stdio.h>
#include <ctype.h>

int compareStrings(const char *str1, const char *str2);

int main(void){

    char firstStr[30], secondStr[30];
    printf("Enter first string: ");
    scanf("%s", firstStr);
    printf("Enter second string: ");
    scanf("%s", secondStr);

    int cmp = compareStrings(firstStr, secondStr);

    if (cmp < 0)
        printf("\'%s\' comes before the \'%s\'", firstStr, secondStr);
    else if (cmp > 0)
        printf("\'%s\' comes before the \'%s\'", secondStr, firstStr);
    else
        printf("Strings are equal...");

    return 0;
}

int compareStrings(const char *str1, const char *str2){
    
    while (*str1 && *str2) {
        char ch1 = tolower(*str1);
        char ch2 = tolower(*str2);

        if (ch1 < ch2) 
            return -1;
        else if (ch1 > ch2) 
            return 1;
        
        str1++;
        str2++;
    }

    if (*str1 == '\0' && *str2 != '\0')
        return -1;
    if (*str2 == '\0' && *str1 != '\0')
        return 1;

    return 0;
}
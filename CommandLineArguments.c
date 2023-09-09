#include <stdio.h>
#include <stdlib.h>

/*
    argc: Argument count is an integer variable that stores the number of command line arguments passed
    by the user including the name of the program.
    argv: Argument Vector is an array of character pointers listing all the arguments.

    argv[0]: holds the name of the program
    argv[1]: points the first command line argument
    argv[argc-1]: points the last argument
*/

int main(int argc, char *argv[]){
    
    if (argc != 2) {
        fprintf(stderr, "You have to enter two argument!\n");
        exit(EXIT_FAILURE);
    }
    
    int i, times = atoi(argv[1]);

    for (i = 0; i < times; i++)
        printf("%02d- Hello, World!\n", i + 1);
    
    return 0;
}
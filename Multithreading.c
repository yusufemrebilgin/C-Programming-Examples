// Multithreading for Windows
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NUM_OF_THREADS 5

DWORD WINAPI threadFunction(LPVOID lpParam) {
    int i, id = *((int *)lpParam);
    int end = *((int *)lpParam + 1);

    for (i = 1; i <= end; i++) {
        printf("Thread #%d: %d\n", id, i);
        Sleep(1000);
    }
  
    return 0;
}

int main(void) {

    int i, n;
    printf("Count one to ... : ");
    scanf("%d", &n);

    int params[NUM_OF_THREADS][2];
    HANDLE threads[NUM_OF_THREADS];
    DWORD threadIds[NUM_OF_THREADS];

    for (i = 0; i < NUM_OF_THREADS; i++) {
        params[i][0] = i + 1;   // Thread id
        params[i][1] = n;       // Sayılacak son sayı

        threads[i] = CreateThread(NULL, 0, threadFunction, (LPVOID)&params[i], 0, &threadIds[i]);
        if (threads[i] == NULL) {
            fprintf(stderr, "Thread creation failed..");
            return EXIT_FAILURE;
        }
    }

    WaitForMultipleObjects(NUM_OF_THREADS, threads, TRUE, INFINITE);

    for (i = 0; i < NUM_OF_THREADS; i++)
        CloseHandle(threads[i]);

    return 0;
}
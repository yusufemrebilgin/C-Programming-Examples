#include <stdio.h>
#define M 6
#define N 12

void print(int arr[M][N]);
void findPath(int maze[M][N], int path[M][N], int x, int y);

int main(void){

    int maze[M][N] = {  
                        {1,0,1,1,1,0,0,1,0,1,1,0},
                        {1,0,1,1,1,1,1,0,1,0,0,0},
                        {1,1,1,1,1,1,1,0,1,0,1,0},
                        {0,1,0,1,0,1,0,1,1,1,1,1},
                        {0,1,0,1,1,1,1,1,0,0,0,1},
                        {1,1,1,0,1,1,1,1,1,1,1,1}
                                                    };

    int path[M][N] = {0};

    printf("Maze\n\n");
    print(maze);

    findPath(maze, path, 0, 0);

    printf("Shortest Path:\n\n");
    print(path);

    return 0;
}

void findPath(int maze[M][N], int path[M][N], int x, int y){

    static int minCost, maxCost = M * N;
    maze[x][y] = 2;
    minCost++;

    if (minCost < maxCost && (x == M - 1 && y == N - 1)) {
        int i, j;
        maxCost = minCost;
        for (i = 0; i < M; i ++)
            for (j = 0; j < N; j++)
                path[i][j] = (maze[i][j]) == 2 ? 1 : 0;
        minCost = 0;
    }

    if (maze[x + 1][y] == 1 && maze[x + 1][y] != 2)
        findPath(maze, path, x + 1, y);
    if (maze[x - 1][y] == 1 && maze[x - 1][y] != 2)
        findPath(maze, path, x - 1, y);
    if (maze[x][y + 1] == 1 && maze[x][y + 1] != 2)
        findPath(maze, path, x, y + 1);
    if (maze[x][y - 1] == 1 && maze[x][y - 1] != 2)
        findPath(maze, path, x, y - 1);
    
    maze[x][y] = 1;
    minCost--;
}

void print(int arr[M][N]){
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
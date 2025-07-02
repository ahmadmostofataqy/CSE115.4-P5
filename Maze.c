#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50

int maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int size;

void createMaze(int seed) {
    int i, j;

    if (seed == -1)
        srand(time(0));
    else
        srand(seed);

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
                maze[i][j] = 1;
            else
                maze[i][j] = rand() % 2;

            visited[i][j] = 0;
        }
    }

    maze[0][0] = 0;
    maze[size - 1][size - 1] = 0;
}

void showMaze() {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (i == 0 && j == 0)
                printf("S ");
            else if (i == size - 1 && j == size - 1)
                printf("E ");
            else
                printf("%c ", maze[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

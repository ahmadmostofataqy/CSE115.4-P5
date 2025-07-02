#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 50 // Safety limit

int maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

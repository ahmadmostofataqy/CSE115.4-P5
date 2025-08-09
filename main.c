#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 7
int maze[n][n];
int visited[n][n];

void generate_maze();
void print_matrix(int matrix[n][n]);
int solve_maze(int x, int y);

int main() {
    generate_maze();

    printf("Generated Maze:\n");
    print_matrix(maze);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;

    if (solve_maze(0, 0)) {
        printf("Path Found:\n");
        print_matrix(visited);
    } else {
        printf("No Path Found.\n");
    }

    return 0;
}

void generate_maze() {
    srand(time(NULL));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 100 < 70) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }

    maze[0][0] = 1;
    maze[n - 1][n - 1] = 1;
}

void print_matrix(int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solve_maze(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return 0;
    if (maze[x][y] == 0 || visited[x][y] == 1) return 0;

    visited[x][y] = 1;

    if (x == n - 1 && y == n - 1) return 1;

    if (solve_maze(x, y + 1)) return 1;
    if (solve_maze(x + 1, y)) return 1;
    if (solve_maze(x, y - 1)) return 1;
    if (solve_maze(x - 1, y)) return 1;

    visited[x][y] = 0;
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 7
int maze[n][n];

void generate_maze();
void print_matrix(int matrix[n][n]);

int main() {
    generate_maze();

    printf("Generated Maze:\n");
    print_matrix(maze);

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
 

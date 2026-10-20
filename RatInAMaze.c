#include <stdio.h>

#define N 4

int isSafe(int maze[N][N], int row, int col) {

    if (row >= 0 && row < N &&
        col >= 0 && col < N &&
        maze[row][col] == 1) {

        return 1;
    }

    return 0;
}

int solveMaze(int maze[N][N],
              int row,
              int col,
              int solution[N][N]) {

    // Destination reached
    if (row == N - 1 &&
        col == N - 1 &&
        maze[row][col] == 1) {

        solution[row][col] = 1;
        return 1;
    }

    if (isSafe(maze, row, col)) {

        // Include current cell
        solution[row][col] = 1;

        // Try moving right
        if (solveMaze(maze,
                      row,
                      col + 1,
                      solution)) {

            return 1;
        }

        // Try moving down
        if (solveMaze(maze,
                      row + 1,
                      col,
                      solution)) {

            return 1;
        }

        // Backtrack
        solution[row][col] = 0;

        return 0;
    }

    return 0;
}

void printSolution(int solution[N][N]) {

    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++) {

            printf("%d ", solution[i][j]);
        }

        printf("\n");
    }
}

int main() {

    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int solution[N][N] = {0};

    if (solveMaze(maze, 0, 0, solution)) {

        printf("Path found:\n");

        printSolution(solution);

    } else {

        printf("No path exists.\n");
    }

    return 0;
}
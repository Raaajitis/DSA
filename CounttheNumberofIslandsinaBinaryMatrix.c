#include <stdio.h>

#define ROWS 4
#define COLS 5

void dfs(int grid[ROWS][COLS],
         int row,
         int col) {

    // Check boundaries
    if (row < 0 || row >= ROWS ||
        col < 0 || col >= COLS) {

        return;
    }

    // Water or already visited
    if (grid[row][col] == 0) {
        return;
    }

    // Mark current land as visited
    grid[row][col] = 0;

    // Visit all four directions
    dfs(grid, row - 1, col);
    dfs(grid, row + 1, col);
    dfs(grid, row, col - 1);
    dfs(grid, row, col + 1);
}

int countIslands(int grid[ROWS][COLS]) {

    int islands = 0;

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            if (grid[i][j] == 1) {

                islands++;

                // Remove the entire connected island
                dfs(grid, i, j);
            }
        }
    }

    return islands;
}

int main() {

    int grid[ROWS][COLS] = {

        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 1}

    };

    int result = countIslands(grid);

    printf("Number of islands: %d\n", result);

    return 0;
}
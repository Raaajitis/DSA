// File: count_diagonal_islands.c
#include <stdio.h>

int rows, cols;

int isSafe(int r, int c, int grid[50][50], int visited[50][50]) {
    return (r >= 0 && r < rows &&
            c >= 0 && c < cols &&
            grid[r][c] == 1 && !visited[r][c]);
}

void dfs(int r, int c, int grid[50][50], int visited[50][50]) {
    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};

    visited[r][c] = 1;

    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isSafe(nr, nc, grid, visited))
            dfs(nr, nc, grid, visited);
    }
}

int countIslands(int grid[50][50]) {
    int visited[50][50] = {0};
    int count = 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1 && !visited[r][c]) {
                dfs(r, c, grid, visited);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int grid[50][50] = {
        {1,1,0},
        {0,1,0},
        {1,0,1}
    };

    rows = 3;
    cols = 3;

    printf("Number of Islands: %d\n", countIslands(grid));
    return 0;
}


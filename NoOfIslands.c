#include <stdio.h>

#define ROW 3
#define COL 4

void dfs(int grid[ROW][COL], int i, int j) {

    if (i < 0 || j < 0 || i >= ROW || j >= COL || grid[i][j] == 0)
        return;

    grid[i][j] = 0;

    dfs(grid, i+1, j);
    dfs(grid, i-1, j);
    dfs(grid, i, j+1);
    dfs(grid, i, j-1);
}

int countIslands(int grid[ROW][COL]) {

    int count = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {

            if (grid[i][j] == 1) {
                dfs(grid, i, j);
                count++;
            }
        }
    }

    return count;
}

int main() {

    int grid[ROW][COL] = {
        {1,1,0,0},
        {1,0,0,1},
        {0,0,1,1}
    };

    printf("Number of Islands: %d\n", countIslands(grid));

    return 0;
}
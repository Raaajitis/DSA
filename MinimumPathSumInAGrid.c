#include <stdio.h>

#define ROWS 3
#define COLS 3

int min(int a, int b) {

    return (a < b) ? a : b;
}

int minimumPathSum(int grid[ROWS][COLS]) {

    int dp[ROWS][COLS];

    // Starting cell
    dp[0][0] = grid[0][0];

    // First row
    for (int j = 1; j < COLS; j++) {

        dp[0][j] =
            dp[0][j - 1] + grid[0][j];
    }

    // First column
    for (int i = 1; i < ROWS; i++) {

        dp[i][0] =
            dp[i - 1][0] + grid[i][0];
    }

    // Remaining cells
    for (int i = 1; i < ROWS; i++) {

        for (int j = 1; j < COLS; j++) {

            dp[i][j] =
                grid[i][j] +
                min(dp[i - 1][j],
                    dp[i][j - 1]);
        }
    }

    return dp[ROWS - 1][COLS - 1];
}

int main() {

    int grid[ROWS][COLS] = {

        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}

    };

    int result = minimumPathSum(grid);

    printf("Minimum path sum: %d\n", result);

    return 0;
}
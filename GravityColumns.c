#include <stdio.h>

#define MAXN 1000
#define MAXM 1000

int grid[MAXN][MAXM];

void applyGravity(int n, int m) {

    for (int col = 0; col < m; col++) {

        int ones = 0;

        /* Count 1s in this column */
        for (int row = 0; row < n; row++) {
            if (grid[row][col] == 1)
                ones++;
        }

        /* Clear the column */
        for (int row = 0; row < n; row++)
            grid[row][col] = 0;

        /* Put all 1s at the bottom */
        for (int row = n - ones; row < n; row++)
            grid[row][col] = 1;
    }
}

void rotateRowRight(int row, int m) {

    int last = grid[row][m - 1];

    for (int col = m - 1; col > 0; col--)
        grid[row][col] = grid[row][col - 1];

    grid[row][0] = last;
}

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    /* First gravity operation */
    applyGravity(n, m);

    /*
     * Find the topmost row having
     * the maximum number of 1s.
     */
    int bestRow = 0;
    int bestCount = -1;

    for (int row = 0; row < n; row++) {

        int count = 0;

        for (int col = 0; col < m; col++)
            count += grid[row][col];

        if (count > bestCount) {
            bestCount = count;
            bestRow = row;
        }
    }

    /* Rotate selected row */
    rotateRowRight(bestRow, m);

    /* Gravity again */
    applyGravity(n, m);

    /* Print final grid */
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {
            printf("%d", grid[i][j]);

            if (j + 1 < m)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}
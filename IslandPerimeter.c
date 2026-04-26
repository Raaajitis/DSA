#include <stdio.h>

int islandPerimeter(int grid[10][10], int r, int c) {

    int perimeter = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            if (grid[i][j] == 1) {

                perimeter += 4;

                if (i > 0 && grid[i-1][j] == 1)
                    perimeter -= 2;

                if (j > 0 && grid[i][j-1] == 1)
                    perimeter -= 2;
            }
        }
    }

    return perimeter;
}

int main() {

    int grid[10][10] = {
        {1,1,0,0},
        {1,1,0,0},
        {0,0,1,1},
        {0,0,1,1}
    };

    printf("Perimeter: %d\n", islandPerimeter(grid,4,4));

    return 0;
}
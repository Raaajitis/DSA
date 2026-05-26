#include <stdio.h>

#define ROW 2
#define COL 2

int perimeter(int grid[ROW][COL]) {

    int peri = 0;

    for (int i = 0; i < ROW; i++) {

        for (int j = 0; j < COL; j++) {

            if (grid[i][j] == 1) {

                peri += 4;

                if (i > 0 && grid[i-1][j] == 1)
                    peri -= 2;

                if (j > 0 && grid[i][j-1] == 1)
                    peri -= 2;
            }
        }
    }

    return peri;
}

int main() {

    int grid[ROW][COL] = {
        {1,1},
        {1,0}
    };

    printf("Perimeter: %d\n",
           perimeter(grid));

    return 0;
}
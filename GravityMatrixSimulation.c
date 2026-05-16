#include <stdio.h>

#define ROW 3
#define COL 3

void applyGravity(char grid[ROW][COL]) {

    for (int col = 0; col < COL; col++) {

        int empty = ROW - 1;

        for (int row = ROW - 1; row >= 0; row--) {

            if (grid[row][col] == '*') {
                empty = row - 1;
            }

            else if (grid[row][col] == '#') {

                char temp = grid[row][col];
                grid[row][col] = '.';
                grid[empty][col] = temp;

                empty--;
            }
        }
    }
}

void printGrid(char grid[ROW][COL]) {

    for (int i = 0; i < ROW; i++) {

        for (int j = 0; j < COL; j++)
            printf("%c ", grid[i][j]);

        printf("\n");
    }
}

int main() {

    char grid[ROW][COL] = {
        {'#', '.', '*'},
        {'#', '#', '.'},
        {'.', '.', '#'}
    };

    applyGravity(grid);

    printGrid(grid);

    return 0;
}
#include <stdio.h>

#define ROWS 3
#define COLS 3
#define MAX 100

struct Orange {
    int row;
    int col;
    int time;
};

int rottenOranges(int grid[ROWS][COLS]) {

    struct Orange queue[MAX];

    int front = 0;
    int rear = 0;

    int fresh = 0;
    int maxTime = 0;

    // Store all initially rotten oranges
    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            if (grid[i][j] == 2) {

                queue[rear].row = i;
                queue[rear].col = j;
                queue[rear].time = 0;

                rear++;
            }

            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    // Directions:
    // up, down, left, right

    int rowDirection[] = {-1, 1, 0, 0};
    int colDirection[] = {0, 0, -1, 1};

    while (front < rear) {

        struct Orange current = queue[front];
        front++;

        for (int i = 0; i < 4; i++) {

            int newRow =
                current.row + rowDirection[i];

            int newCol =
                current.col + colDirection[i];

            // Check boundaries
            if (newRow >= 0 &&
                newRow < ROWS &&
                newCol >= 0 &&
                newCol < COLS &&
                grid[newRow][newCol] == 1) {

                // Make fresh orange rotten
                grid[newRow][newCol] = 2;

                fresh--;

                queue[rear].row = newRow;
                queue[rear].col = newCol;
                queue[rear].time = current.time + 1;

                if (current.time + 1 > maxTime) {
                    maxTime = current.time + 1;
                }

                rear++;
            }
        }
    }

    // Some fresh oranges could not be reached
    if (fresh > 0) {
        return -1;
    }

    return maxTime;
}

int main() {

    int grid[ROWS][COLS] = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = rottenOranges(grid);

    if (result == -1) {

        printf("Not all oranges can become rotten.\n");

    } else {

        printf("Minimum time required: %d minutes\n",
               result);
    }

    return 0;
}
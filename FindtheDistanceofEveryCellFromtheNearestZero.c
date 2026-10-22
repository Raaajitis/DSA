#include <stdio.h>

#define ROWS 3
#define COLS 3
#define MAX 100

struct Cell {

    int row;
    int col;
};

void nearestZeroDistance(
    int matrix[ROWS][COLS]) {

    int distance[ROWS][COLS];

    struct Cell queue[MAX];

    int front = 0;
    int rear = 0;

    // Initialize distances
    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            if (matrix[i][j] == 0) {

                distance[i][j] = 0;

                queue[rear].row = i;
                queue[rear].col = j;

                rear++;

            } else {

                distance[i][j] = -1;
            }
        }
    }

    int rowDirection[] =
        {-1, 1, 0, 0};

    int colDirection[] =
        {0, 0, -1, 1};

    while (front < rear) {

        struct Cell current =
            queue[front++];

        for (int i = 0; i < 4; i++) {

            int newRow =
                current.row +
                rowDirection[i];

            int newCol =
                current.col +
                colDirection[i];

            if (newRow >= 0 &&
                newRow < ROWS &&
                newCol >= 0 &&
                newCol < COLS &&
                distance[newRow][newCol] == -1) {

                distance[newRow][newCol] =
                    distance[current.row]
                            [current.col] + 1;

                queue[rear].row = newRow;
                queue[rear].col = newCol;

                rear++;
            }
        }
    }

    printf("Distance Matrix:\n");

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            printf("%d ",
                   distance[i][j]);
        }

        printf("\n");
    }
}

int main() {

    int matrix[ROWS][COLS] = {

        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}

    };

    nearestZeroDistance(matrix);

    return 0;
}
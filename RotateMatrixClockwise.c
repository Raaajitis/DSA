#include <stdio.h>

#define ROWS 4
#define COLS 4

void rotateBoundary(int matrix[ROWS][COLS]) {

    int previous;
    int current;

    previous = matrix[0][0];

    // Move across the top row
    for (int j = 1; j < COLS; j++) {

        current = matrix[0][j];
        matrix[0][j] = previous;
        previous = current;
    }

    // Move down the right column
    for (int i = 1; i < ROWS; i++) {

        current = matrix[i][COLS - 1];
        matrix[i][COLS - 1] = previous;
        previous = current;
    }

    // Move across the bottom row
    for (int j = COLS - 2; j >= 0; j--) {

        current = matrix[ROWS - 1][j];
        matrix[ROWS - 1][j] = previous;
        previous = current;
    }

    // Move up the left column
    for (int i = ROWS - 2; i >= 0; i--) {

        current = matrix[i][0];
        matrix[i][0] = previous;
        previous = current;
    }
}

void printMatrix(int matrix[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {
            printf("%3d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main() {

    int matrix[ROWS][COLS] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    rotateBoundary(matrix);

    printf("\nAfter rotating boundary clockwise:\n");
    printMatrix(matrix);

    return 0;
}
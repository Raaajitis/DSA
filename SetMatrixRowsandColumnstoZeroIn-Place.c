#include <stdio.h>

#define ROWS 4
#define COLS 4

void setZeroes(int matrix[ROWS][COLS]) {

    int firstRowZero = 0;
    int firstColZero = 0;

    // Check original first row
    for (int j = 0; j < COLS; j++) {

        if (matrix[0][j] == 0) {
            firstRowZero = 1;
        }
    }

    // Check original first column
    for (int i = 0; i < ROWS; i++) {

        if (matrix[i][0] == 0) {
            firstColZero = 1;
        }
    }

    // Use first row and column as markers
    for (int i = 1; i < ROWS; i++) {

        for (int j = 1; j < COLS; j++) {

            if (matrix[i][j] == 0) {

                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero marked rows
    for (int i = 1; i < ROWS; i++) {

        if (matrix[i][0] == 0) {

            for (int j = 1; j < COLS; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero marked columns
    for (int j = 1; j < COLS; j++) {

        if (matrix[0][j] == 0) {

            for (int i = 1; i < ROWS; i++) {
                matrix[i][j] = 0;
            }
        }
    }

    // Handle first row
    if (firstRowZero) {

        for (int j = 0; j < COLS; j++) {
            matrix[0][j] = 0;
        }
    }

    // Handle first column
    if (firstColZero) {

        for (int i = 0; i < ROWS; i++) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main() {

    int matrix[ROWS][COLS] = {
        {1, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix);

    setZeroes(matrix);

    printf("\nModified Matrix:\n");
    printMatrix(matrix);

    return 0;
}
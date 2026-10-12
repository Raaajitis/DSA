#include <stdio.h>

#define ROWS 4
#define COLS 4

void spiralTraversal(int matrix[ROWS][COLS]) {

    int top = 0;
    int bottom = ROWS - 1;

    int left = 0;
    int right = COLS - 1;

    printf("Spiral order: ");

    while (top <= bottom && left <= right) {

        // Traverse top row
        for (int i = left; i <= right; i++) {

            printf("%d ", matrix[top][i]);
        }

        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++) {

            printf("%d ", matrix[i][right]);
        }

        right--;

        // Traverse bottom row
        if (top <= bottom) {

            for (int i = right; i >= left; i--) {

                printf("%d ", matrix[bottom][i]);
            }

            bottom--;
        }

        // Traverse left column
        if (left <= right) {

            for (int i = bottom; i >= top; i--) {

                printf("%d ", matrix[i][left]);
            }

            left++;
        }
    }

    printf("\n");
}

int main() {

    int matrix[ROWS][COLS] = {

        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}

    };

    spiralTraversal(matrix);

    return 0;
}
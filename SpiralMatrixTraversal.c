#include <stdio.h>

void spiralTraversal(int matrix[][100], int rows, int cols) {
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);

        top++;

        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);

        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);

            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);

            left++;
        }
    }
}

int main() {
    int matrix[100][100] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = 3;
    int cols = 3;

    printf("Spiral Order: ");

    spiralTraversal(matrix, rows, cols);

    return 0;
}
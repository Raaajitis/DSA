#include <stdio.h>

void spiral(int arr[10][10], int r, int c) {

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top <= bottom && left <= right) {

        // Down
        for (int i = top; i <= bottom; i++)
            printf("%d ", arr[i][left]);
        left++;

        // Right
        for (int i = left; i <= right; i++)
            printf("%d ", arr[bottom][i]);
        bottom--;

        if (left <= right) {
            // Up
            for (int i = bottom; i >= top; i--)
                printf("%d ", arr[i][right]);
            right--;
        }

        if (top <= bottom) {
            // Left
            for (int i = right; i >= left; i--)
                printf("%d ", arr[top][i]);
            top++;
        }
    }
}

int main() {

    int arr[10][10] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    spiral(arr, 3, 4);

    return 0;
}
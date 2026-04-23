#include <stdio.h>

void rotateLayer(int arr[10][10], int top, int left, int bottom, int right) {

    int prev = arr[top+1][left];

    // top row
    for (int i = left; i <= right; i++) {
        int temp = arr[top][i];
        arr[top][i] = prev;
        prev = temp;
    }
    top++;

    // right column
    for (int i = top; i <= bottom; i++) {
        int temp = arr[i][right];
        arr[i][right] = prev;
        prev = temp;
    }
    right--;

    // bottom row
    for (int i = right; i >= left; i--) {
        int temp = arr[bottom][i];
        arr[bottom][i] = prev;
        prev = temp;
    }
    bottom--;

    // left column
    for (int i = bottom; i >= top; i--) {
        int temp = arr[i][left];
        arr[i][left] = prev;
        prev = temp;
    }
}

void rotateMatrix(int arr[10][10], int r, int c) {

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while (top < bottom && left < right) {
        rotateLayer(arr, top, left, bottom, right);
        top++; bottom--; left++; right--;
    }
}

int main() {

    int arr[10][10] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    rotateMatrix(arr, 4, 4);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}
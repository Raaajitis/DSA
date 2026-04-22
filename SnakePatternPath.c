#include <stdio.h>

void snake(int arr[10][10], int r, int c) {

    int result[100], k = 0;

    for (int i = 0; i < r; i++) {

        if (i % 2 == 0) {
            for (int j = 0; j < c; j++)
                result[k++] = arr[i][j];
        } else {
            for (int j = c - 1; j >= 0; j--)
                result[k++] = arr[i][j];
        }
    }

    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);
}

int main() {

    int arr[10][10] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    snake(arr, 3, 4);

    return 0;
}
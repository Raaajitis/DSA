#include <stdio.h>

void reverse(int arr[], int start, int end) {

    while (start < end) {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void rotateRight(int arr[], int n, int k) {

    if (n == 0) {
        return;
    }

    // Handles k greater than n
    k = k % n;

    if (k == 0) {
        return;
    }

    // Step 1: Reverse entire array
    reverse(arr, 0, n - 1);

    // Step 2: Reverse first k elements
    reverse(arr, 0, k - 1);

    // Step 3: Reverse remaining elements
    reverse(arr, k, n - 1);
}

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    printf("Original array:\n");
    printArray(arr, n);

    rotateRight(arr, n, k);

    printf("Array after rotation:\n");
    printArray(arr, n);

    return 0;
}
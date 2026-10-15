#include <stdio.h>

void rearrange(int arr[], int n) {

    // Encode old and new values together
    for (int i = 0; i < n; i++) {

        int newValue = arr[arr[i] % n] % n;

        arr[i] = arr[i] + newValue * n;
    }

    // Extract the new values
    for (int i = 0; i < n; i++) {

        arr[i] = arr[i] / n;
    }
}

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {3, 2, 0, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    rearrange(arr, n);

    printf("Rearranged array:\n");
    printArray(arr, n);

    return 0;
}
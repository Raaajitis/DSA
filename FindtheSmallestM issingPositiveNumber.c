#include <stdio.h>

int firstMissingPositive(int arr[], int n) {

    for (int i = 0; i < n; i++) {

        while (arr[i] > 0 &&
               arr[i] <= n &&
               arr[arr[i] - 1] != arr[i]) {

            int correctIndex = arr[i] - 1;

            int temp = arr[i];
            arr[i] = arr[correctIndex];
            arr[correctIndex] = temp;
        }
    }

    for (int i = 0; i < n; i++) {

        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {

    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = firstMissingPositive(arr, n);

    printf("Smallest missing positive number: %d\n", result);

    return 0;
}
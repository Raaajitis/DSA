#include <stdio.h>

int findEquilibriumIndex(int arr[], int n) {

    int totalSum = 0;
    int leftSum = 0;

    // Calculate total array sum
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    for (int i = 0; i < n; i++) {

        // Remove current element
        // Now totalSum represents right sum
        totalSum -= arr[i];

        if (leftSum == totalSum) {
            return i;
        }

        // Add current element to left side
        leftSum += arr[i];
    }

    return -1;
}

int main() {

    int arr[] = {-7, 1, 5, 2, -4, 3, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findEquilibriumIndex(arr, n);

    if (result == -1) {

        printf("No equilibrium index exists.\n");

    } else {

        printf("Equilibrium index: %d\n", result);
        printf("Element at equilibrium index: %d\n",
               arr[result]);
    }

    return 0;
}
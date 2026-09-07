#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int maxCircularSum(int arr[], int n) {
    int totalSum = arr[0];

    int currentMax = arr[0];
    int maxSum = arr[0];

    int currentMin = arr[0];
    int minSum = arr[0];

    for (int i = 1; i < n; i++) {
        currentMax = max(arr[i], currentMax + arr[i]);
        maxSum = max(maxSum, currentMax);

        currentMin = min(arr[i], currentMin + arr[i]);
        minSum = min(minSum, currentMin);

        totalSum += arr[i];
    }

    if (maxSum < 0)
        return maxSum;

    return max(maxSum, totalSum - minSum);
}

int main() {
    int arr[] = {5, -3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum Circular Subarray Sum: %d\n",
           maxCircularSum(arr, n));

    return 0;
}
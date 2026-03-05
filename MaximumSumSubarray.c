#include <stdio.h>

int maxSubarraySum(int arr[], int n) {
    int currentSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < n; i++) {

        if (currentSum < 0)
            currentSum = arr[i];
        else
            currentSum += arr[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main() {

    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum Subarray Sum: %d\n", maxSubarraySum(arr, n));

    return 0;
}
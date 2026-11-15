#include <stdio.h>

#define MAX_SUM 1000

int canPartition(int arr[], int n) {

    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    // Odd sum cannot be divided equally
    if (totalSum % 2 != 0) {
        return 0;
    }

    int target = totalSum / 2;

    int dp[MAX_SUM + 1] = {0};

    dp[0] = 1;

    for (int i = 0; i < n; i++) {

        /*
         * Traverse backwards so arr[i]
         * cannot be reused multiple times.
         */
        for (int sum = target;
             sum >= arr[i];
             sum--) {

            if (dp[sum - arr[i]]) {
                dp[sum] = 1;
            }
        }
    }

    return dp[target];
}

int main() {

    int arr[] = {1, 5, 11, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartition(arr, n)) {

        printf("Equal partition is possible.\n");

    } else {

        printf("Equal partition is not possible.\n");
    }

    return 0;
}
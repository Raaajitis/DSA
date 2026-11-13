#include <stdio.h>

int longestIncreasingSubsequence(int arr[], int n) {

    if (n == 0) {
        return 0;
    }

    int dp[n];
    int maximum = 1;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[j] < arr[i] &&
                dp[j] + 1 > dp[i]) {

                dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] > maximum) {
            maximum = dp[i];
        }
    }

    return maximum;
}

int main() {

    int arr[] = {
        10, 9, 2, 5, 3, 7, 101, 18
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    int result =
        longestIncreasingSubsequence(arr, n);

    printf("Length of LIS: %d\n", result);

    return 0;
}
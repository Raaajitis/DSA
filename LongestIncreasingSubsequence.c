#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    int dp[n];

    // Each element is LIS of length 1 initially
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    // Build LIS DP
    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find maximum LIS value
    int lis = 0;
    for (int i = 0; i < n; i++)
        lis = max(lis, dp[i]);

    printf("Length of LIS = %d", lis);

    return 0;
}

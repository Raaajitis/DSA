#include <stdio.h>

int main() {

    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;

    int sum = 9;

    int dp[n + 1][sum + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1; // Sum 0 is always possible
    }

    for (int j = 1; j <= sum; j++) {
        dp[0][j] = 0; // No elements → no sum possible
    }

    // Build DP table
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= sum; j++) {

            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    if (dp[n][sum])
        printf("Subset with sum %d exists!", sum);
    else
        printf("Subset with sum %d does NOT exist!", sum);

    return 0;
}

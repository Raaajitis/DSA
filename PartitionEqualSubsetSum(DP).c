#include <stdio.h>

int main() {

    int arr[] = {1, 5, 11, 5};
    int n = 4;

    int totalSum = 0;

    // Calculate total sum
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    // If sum is odd, cannot partition
    if (totalSum % 2 != 0) {
        printf("Cannot be partitioned!");
        return 0;
    }

    int target = totalSum / 2;

    int dp[n + 1][target + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= target; j++)
        dp[0][j] = 0;

    // Subset Sum DP
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= target; j++) {

            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    if (dp[n][target])
        printf("Can be partitioned into two equal subsets!");
    else
        printf("Cannot be partitioned into two equal subsets!");

    return 0;
}

#include <stdio.h>
#include <limits.h>

int main() {

    int arr[] = {10, 30, 5, 60};
    int n = 4;

    int dp[n][n];

    // dp[i][i] = 0
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Chain length
    for (int len = 2; len < n; len++) {

        for (int i = 1; i < n - len + 1; i++) {

            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k] + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum multiplications = %d", dp[1][n - 1]);

    return 0;
}

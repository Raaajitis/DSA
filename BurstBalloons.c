#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int nums[] = {1, 3, 1, 5, 8, 1};
    int n = 6;  // added 1 at start and end

    int dp[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    for (int len = 2; len < n; len++) {

        for (int left = 0; left < n - len; left++) {

            int right = left + len;

            for (int k = left + 1; k < right; k++) {

                int coins = nums[left] * nums[k] * nums[right]
                          + dp[left][k]
                          + dp[k][right];

                dp[left][right] = max(dp[left][right], coins);
            }
        }
    }

    printf("Maximum Coins = %d", dp[0][n - 1]);

    return 0;
}
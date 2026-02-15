#include <stdio.h>

#define INF 9999

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {

    int coins[] = {1, 2, 5};
    int n = 3;

    int amount = 11;

    int dp[amount + 1];

    // Initialize DP array
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = INF;

    // Build DP table
    for (int i = 1; i <= amount; i++) {

        for (int j = 0; j < n; j++) {

            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    printf("Minimum coins needed = %d", dp[amount]);

    return 0;
}

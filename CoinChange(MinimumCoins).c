#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {

    int coins[] = {1, 2, 5};
    int n = 3;
    int amount = 11;

    int dp[amount + 1];

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= amount; i++) {

        for (int j = 0; j < n; j++) {

            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    printf("Minimum coins = %d", dp[amount]);

    return 0;
}
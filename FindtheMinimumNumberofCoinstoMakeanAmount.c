#include <stdio.h>

#define MAX 1000

int minimumCoins(int coins[],
                 int n,
                 int amount) {

    int dp[MAX];

    // Initialize all amounts as unreachable
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    for (int current = 1;
         current <= amount;
         current++) {

        for (int j = 0; j < n; j++) {

            if (coins[j] <= current) {

                int previous =
                    current - coins[j];

                if (dp[previous] + 1 <
                    dp[current]) {

                    dp[current] =
                        dp[previous] + 1;
                }
            }
        }
    }

    if (dp[amount] == amount + 1) {
        return -1;
    }

    return dp[amount];
}

int main() {

    int coins[] = {1, 3, 4};

    int n = sizeof(coins) / sizeof(coins[0]);

    int amount = 6;

    int result =
        minimumCoins(coins, n, amount);

    if (result == -1) {

        printf("The amount cannot be formed.\n");

    } else {

        printf("Minimum number of coins: %d\n",
               result);
    }

    return 0;
}
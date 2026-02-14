#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int weight[] = {2, 3, 5};
    int value[]  = {10, 15, 25};

    int n = 3;
    int W = 5;

    int dp[n + 1][W + 1];

    // Build DP table
    for (int i = 0; i <= n; i++) {

        for (int w = 0; w <= W; w++) {

            // Base case
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            // If item fits
            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );

            // If item doesn't fit
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value in Knapsack = %d", dp[n][W]);

    return 0;
}

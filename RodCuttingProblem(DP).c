#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int price[] = {2, 5, 7, 8};
    int n = 4;

    int dp[n + 1];

    dp[0] = 0;

    // Build DP solution
    for (int i = 1; i <= n; i++) {

        int best = 0;

        for (int j = 0; j < i; j++) {
            best = max(best, price[j] + dp[i - j - 1]);
        }

        dp[i] = best;
    }

    printf("Maximum Profit = %d", dp[n]);

    return 0;
}

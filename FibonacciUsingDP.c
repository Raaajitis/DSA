#include <stdio.h>

int main() {

    int n = 6;

    int dp[100];

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Build Fibonacci using DP
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("Fibonacci(%d) = %d", n, dp[n]);

    return 0;
}

#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int eggs = 2;
    int floors = 10;

    int dp[eggs + 1][floors + 1];

    for (int i = 1; i <= eggs; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 1; j <= floors; j++)
        dp[1][j] = j;

    for (int e = 2; e <= eggs; e++) {
        for (int f = 2; f <= floors; f++) {

            dp[e][f] = INT_MAX;

            for (int k = 1; k <= f; k++) {

                int attempts = 1 + max(
                    dp[e - 1][k - 1],
                    dp[e][f - k]
                );

                dp[e][f] = min(dp[e][f], attempts);
            }
        }
    }

    printf("Minimum Attempts = %d", dp[eggs][floors]);

    return 0;
}
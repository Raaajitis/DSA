#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long minimum(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    long long **dungeon = malloc(n * sizeof(long long *));

    for (int row = 0; row < n; row++) {
        dungeon[row] = malloc(m * sizeof(long long));

        for (int column = 0; column < m; column++) {
            scanf("%lld", &dungeon[row][column]);
        }
    }

    const long long INFINITY = LLONG_MAX / 4;
    long long *dp = malloc((m + 1) * sizeof(long long));

    for (int column = 0; column <= m; column++) {
        dp[column] = INFINITY;
    }

    /*
     * Virtual cell to the right of the destination.
     */
    dp[m - 1] = 1;

    for (int row = n - 1; row >= 0; row--) {
        for (int column = m - 1; column >= 0; column--) {
            long long nextRequired;

            if (column == m - 1) {
                nextRequired = dp[column];
            } else {
                nextRequired = minimum(
                    dp[column],
                    dp[column + 1]
                );
            }

            long long required =
                nextRequired - dungeon[row][column];

            dp[column] = required > 1 ? required : 1;
        }
    }

    printf("%lld\n", dp[0]);

    for (int row = 0; row < n; row++) {
        free(dungeon[row]);
    }

    free(dungeon);
    free(dp);

    return 0;
}
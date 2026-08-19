#include <stdio.h>

#define MAXN 100005
#define INF 1000000000000000000LL

long long dp[MAXN];
long long best[30];

int main() {

    int n;

    scanf("%d", &n);

    int a[MAXN];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int bit = 0; bit < 30; bit++)
        best[bit] = INF;

    dp[0] = 0;

    /*
     * Add index 0 to all bit groups that
     * occur in A[0].
     */
    for (int bit = 0; bit < 30; bit++) {

        if (a[0] & (1 << bit)) {

            long long value =
                dp[0] - 0;

            if (value < best[bit])
                best[bit] = value;
        }
    }

    for (int j = 1; j < n; j++) {

        dp[j] = INF;

        /*
         * Find the best previous index sharing
         * at least one bit with A[j].
         */
        for (int bit = 0; bit < 30; bit++) {

            if (a[j] & (1 << bit)) {

                if (best[bit] != INF) {

                    long long candidate =
                        j + best[bit];

                    if (candidate < dp[j])
                        dp[j] = candidate;
                }
            }
        }

        /*
         * If j is reachable, make it available
         * for future positions.
         */
        if (dp[j] != INF) {

            for (int bit = 0; bit < 30; bit++) {

                if (a[j] & (1 << bit)) {

                    long long value =
                        dp[j] - j;

                    if (value < best[bit])
                        best[bit] = value;
                }
            }
        }
    }

    if (dp[n - 1] == INF)
        printf("-1\n");
    else
        printf("%lld\n", dp[n - 1]);

    return 0;
}
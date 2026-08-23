#include <stdio.h>

#define MAXN 100005

long long a[MAXN];
long long prefix[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);

        prefix[i + 1] =
            prefix[i] + a[i];
    }

    /*
     * dp[i] = maximum number of balanced
     * splits using elements [0 ... i-1].
     */
    int dp[MAXN] = {0};

    for (int i = 1; i <= n; i++) {

        dp[i] = dp[i - 1];

        /*
         * Try every possible balanced split
         * ending at i-1.
         *
         * [j ... k] and [k+1 ... i-1]
         */
        for (int j = 0; j < i - 1; j++) {

            for (int k = j; k < i - 1; k++) {

                long long left =
                    prefix[k + 1] - prefix[j];

                long long right =
                    prefix[i] - prefix[k + 1];

                if (left == right) {

                    int candidate =
                        dp[j] + 1;

                    if (candidate > dp[i])
                        dp[i] = candidate;
                }
            }
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}
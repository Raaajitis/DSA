#include <stdio.h>

#define MAXN 100005

long long price[MAXN];
long long bestSell[MAXN];
long long profit[MAXN];
long long dp[MAXN];

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%lld", &price[i]);

    /*
     * bestSell[i] = maximum price available
     * after day i.
     */
    bestSell[n - 1] = price[n - 1];

    for (int i = n - 2; i >= 0; i--) {

        bestSell[i] =
            max(price[i + 1], bestSell[i + 1]);
    }

    /*
     * Best profit if a transaction starts
     * on day i.
     */
    for (int i = 0; i < n - 1; i++) {

        profit[i] =
            bestSell[i] - price[i];

        if (profit[i] < 0)
            profit[i] = 0;
    }

    /*
     * dp[i] = maximum profit considering
     * days 0...i.
     */
    dp[0] = profit[0];

    for (int i = 1; i < n; i++) {

        /*
         * Don't start a transaction at i.
         */
        dp[i] = dp[i - 1];

        /*
         * Start a transaction at i.
         *
         * The previous transaction must have
         * started at or before i-K.
         */
        long long previous = 0;

        if (i - k >= 0)
            previous = dp[i - k];

        long long candidate =
            previous + profit[i];

        dp[i] = max(dp[i], candidate);
    }

    printf("%lld\n", dp[n - 1]);

    return 0;
}
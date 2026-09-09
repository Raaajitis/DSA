#include <stdio.h>

long long maximum(long long a, long long b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    /*
     * before3 = dp[i - 3]
     * before2 = dp[i - 2]
     * before1 = dp[i - 1]
     */
    long long before3 = 0;
    long long before2 = 0;
    long long before1 = 0;

    for (int i = 1; i <= n; i++) {
        long long coins;
        scanf("%lld", &coins);

        long long selectCurrent = coins + before3;
        long long skipCurrent = before1;
        long long current = maximum(selectCurrent, skipCurrent);

        before3 = before2;
        before2 = before1;
        before1 = current;
    }

    printf("%lld\n", before1);

    return 0;
}
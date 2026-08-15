#include <stdio.h>

#define MAXN 100005
#define INF 1000000000

int a[MAXN];
int dp[MAXN];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        dp[i] = INF;

    dp[0] = 0;

    for (int i = 0; i < n; i++) {

        if (dp[i] == INF)
            continue;

        for (int j = i + 1; j < n; j++) {

            /*
             * Same parity means their sum is even.
             */
            if ((a[i] & 1) == (a[j] & 1)) {

                int cost = dp[i] + (j - i);

                if (cost < dp[j])
                    dp[j] = cost;
            }
        }
    }

    if (dp[n - 1] == INF)
        printf("-1\n");
    else
        printf("%d\n", dp[n - 1]);

    return 0;
}
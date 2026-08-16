#include <stdio.h>

#define MAXN 100005
#define INF 1000000000

int jump[MAXN];
int dp[MAXN];

int main() {

    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &jump[i]);

    for (int i = 1; i <= n; i++)
        dp[i] = INF;

    dp[1] = 0;

    for (int i = 1; i <= n; i++) {

        if (dp[i] == INF)
            continue;

        /*
         * Option 1:
         * Move one position right.
         */
        if (i + 1 <= n) {

            int newCost = dp[i] + 1;

            if (newCost < dp[i + 1])
                dp[i + 1] = newCost;
        }

        /*
         * Option 2:
         * Use teleport from i.
         */
        int destination = jump[i];

        if (destination >= 1 &&
            destination <= n &&
            destination != i) {

            int newCost = dp[i] + 2;

            if (newCost < dp[destination])
                dp[destination] = newCost;
        }
    }

    if (dp[n] == INF)
        printf("-1\n");
    else
        printf("%d\n", dp[n]);

    return 0;
}
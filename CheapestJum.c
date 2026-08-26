#include <stdio.h>

#define MAXN 100005
#define INF 1000000000000000000LL

typedef long long ll;

ll a[MAXN];
ll dp[MAXN];

int deque[MAXN];

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    dp[1] = a[1];

    int front = 0;
    int back = 0;

    /*
     * Position 1 is initially available.
     */
    deque[back++] = 1;

    for (int i = 2; i <= n; i++) {

        /*
         * Remove positions that are outside
         * the allowed jump range.
         */
        while (front < back &&
               deque[front] < i - k) {

            front++;
        }

        /*
         * If there is no reachable position,
         * this position cannot be reached.
         */
        if (front == back) {

            dp[i] = INF;

        } else {

            dp[i] =
                dp[deque[front]] + a[i];
        }

        /*
         * Maintain increasing dp values.
         *
         * Any position with a larger/equal dp
         * value can never become useful before
         * the smaller one.
         */
        while (front < back &&
               dp[deque[back - 1]] >= dp[i]) {

            back--;
        }

        deque[back++] = i;
    }

    if (dp[n] == INF)
        printf("-1\n");
    else
        printf("%lld\n", dp[n]);

    return 0;
}
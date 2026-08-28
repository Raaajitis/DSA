#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main() {

    int n;
    scanf("%d", &n);

    ll *fuel = malloc(n * sizeof(ll));
    ll *cost = malloc(n * sizeof(ll));

    for (int i = 0; i < n; i++)
        scanf("%lld", &fuel[i]);

    for (int i = 0; i < n; i++)
        scanf("%lld", &cost[i]);

    ll total = 0;
    ll current = 0;

    int start = 0;

    for (int i = 0; i < n; i++) {

        ll gain = fuel[i] - cost[i];

        total += gain;
        current += gain;

        /*
         * Starting from 'start' cannot reach
         * station i+1.
         */
        if (current < 0) {

            start = i + 1;
            current = 0;
        }
    }

    /*
     * If total fuel is less than total cost,
     * completing the circle is impossible.
     */
    if (total < 0)
        printf("-1\n");
    else
        printf("%d\n", start);

    free(fuel);
    free(cost);

    return 0;
}
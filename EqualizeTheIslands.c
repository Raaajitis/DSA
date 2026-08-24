#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

long long a[MAXN];

long long absoluteValue(long long x) {
    return x < 0 ? -x : x;
}

int main() {

    int n;
    scanf("%d", &n);

    long long total = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        total += a[i];
    }

    /* Equal population is impossible. */
    if (total % n != 0) {
        printf("-1\n");
        return 0;
    }

    long long target = total / n;

    long long balance = 0;
    long long operations = 0;

    for (int i = 0; i < n - 1; i++) {

        /*
         * Positive balance:
         * left side has extra people.
         *
         * Negative balance:
         * left side needs people.
         */
        balance += a[i] - target;

        operations += absoluteValue(balance);
    }

    printf("%lld\n", operations);

    return 0;
}
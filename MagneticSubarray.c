#include <stdio.h>

#define MAXN 1005

int a[MAXN];

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long answer = 0;

    for (int l = 0; l < n; l++) {

        long long difference = 0;
        int maximum = a[l];

        for (int r = l; r < n; r++) {

            /*
             * Position r-l is relative to the
             * beginning of the subarray.
             */
            if ((r - l) % 2 == 0)
                difference += a[r];
            else
                difference -= a[r];

            if (a[r] > maximum)
                maximum = a[r];

            if (difference == k || difference == -k)
                answer += maximum;
        }
    }

    printf("%lld\n", answer);

    return 0;
}
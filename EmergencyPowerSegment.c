#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n;
    long long k;

    scanf("%d %lld", &n, &k);

    long long *prefix = malloc((n + 1) * sizeof(long long));
    int *deque = malloc((n + 1) * sizeof(int));

    prefix[0] = 0;

    for (int i = 1; i <= n; i++) {
        long long value;
        scanf("%lld", &value);
        prefix[i] = prefix[i - 1] + value;
    }

    int front = 0;
    int back = 0;
    int minimumLength = INT_MAX;

    for (int i = 0; i <= n; i++) {
        /*
         * If prefix[i] - prefix[deque[front]] >= k,
         * the corresponding subarray is valid.
         */
        while (front < back &&
               prefix[i] - prefix[deque[front]] >= k) {
            int length = i - deque[front];

            if (length < minimumLength) {
                minimumLength = length;
            }

            front++;
        }

        /*
         * A larger prefix sum at an earlier position is never
         * better than the current smaller prefix sum.
         */
        while (front < back &&
               prefix[deque[back - 1]] >= prefix[i]) {
            back--;
        }

        deque[back++] = i;
    }

    if (minimumLength == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", minimumLength);
    }

    free(prefix);
    free(deque);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int compare(const void *a, const void *b) {

    ll x = *(const ll *)a;
    ll y = *(const ll *)b;

    if (x < y)
        return -1;

    if (x > y)
        return 1;

    return 0;
}

ll absValue(ll x) {
    return x < 0 ? -x : x;
}

int main() {

    int n;
    scanf("%d", &n);

    ll *a = malloc(n * sizeof(ll));
    ll *b = malloc(n * sizeof(ll));

    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    qsort(a, n, sizeof(ll), compare);

    /*
     * Construct an alternating arrangement.
     *
     * Take values from the two ends.
     */
    int left = 0;
    int right = n - 1;
    int pos = 0;

    /*
     * Put the largest value first, then the
     * smallest, then the second largest, etc.
     */
    while (left <= right) {

        if (left == right) {
            b[pos++] = a[left++];
        }
        else {
            b[pos++] = a[right--];
            b[pos++] = a[left++];
        }
    }

    ll answer = 0;

    for (int i = 1; i < n; i++) {

        answer +=
            absValue(b[i] - b[i - 1]);
    }

    printf("%lld\n", answer);

    free(a);
    free(b);

    return 0;
}
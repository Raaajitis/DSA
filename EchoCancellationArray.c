#include <stdio.h>

#define MAXN 100005

int a[MAXN];
int removed[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (1) {
        int first = -1;
        int second = -1;

        /*
         * Find the first pair of equal values.
         */
        for (int i = 0; i < n; i++) {

            if (removed[i])
                continue;

            for (int j = i + 1; j < n; j++) {

                if (removed[j])
                    continue;

                if (a[i] == a[j]) {
                    first = i;
                    second = j;
                    break;
                }
            }

            if (first != -1)
                break;
        }

        if (first == -1)
            break;

        removed[first] = 1;
        removed[second] = 1;
    }

    int count = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        if (!removed[i]) {
            count++;
            sum += a[i];
        }
    }

    printf("%d %lld\n", count, sum);

    return 0;
}
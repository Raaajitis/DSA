#include <stdio.h>

#define MAXN 100005

int a[MAXN];

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long answer = 0;

    for (int start = 0; start < n; start++) {

        int maxPos = 0;
        int maxValue = a[start % n];

        // Find maximum inside circular window
        for (int j = 1; j < k; j++) {

            int pos = (start + j) % n;

            if (a[pos] > maxValue) {
                maxValue = a[pos];
                maxPos = j;
            }
        }

        int evenXor = 0;
        int oddXor = 0;

        /*
         * maxPos becomes position 0 after rotation.
         */
        for (int j = 0; j < k; j++) {

            int originalPos =
                (start + maxPos + j) % n;

            if (j % 2 == 0)
                evenXor ^= a[originalPos];
            else
                oddXor ^= a[originalPos];
        }

        answer += (evenXor ^ oddXor);
    }

    printf("%lld\n", answer);

    return 0;
}
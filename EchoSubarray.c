#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int a[MAXN];
int z[MAXN];

void buildZ(int arr[], int n) {

    int left = 0;
    int right = 0;

    z[0] = n;

    for (int i = 1; i < n; i++) {

        if (i <= right) {
            z[i] = z[i - left];

            if (z[i] > right - i + 1)
                z[i] = right - i + 1;
        }

        while (i + z[i] < n &&
               arr[z[i]] == arr[i + z[i]]) {

            z[i]++;
        }

        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int answer = 0;

    /*
     * For every possible split:
     *
     * [first half][second half]
     *
     * We need the two parts to be identical.
     */
    for (int start = 0; start < n; start++) {

        int remaining = n - start;

        /*
         * A Z-array calculated directly from
         * a[start...] would tell us how many
         * elements match a[start...].
         *
         * For simplicity, build the suffix Z array
         * here.
         */
        int len = remaining;

        int left = 0;
        int right = 0;

        z[0] = len;

        for (int i = 1; i < len; i++) {

            if (i <= right) {
                z[i] = z[i - left];

                if (z[i] > right - i + 1)
                    z[i] = right - i + 1;
            }

            while (i + z[i] < len &&
                   a[start + z[i]] ==
                   a[start + i + z[i]]) {

                z[i]++;
            }

            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
        }

        /*
         * If z[k] >= k, then:
         *
         * A[start ... start+k-1]
         *
         * equals
         *
         * A[start+k ... start+2k-1]
         */
        for (int k = 1; 2 * k <= len; k++) {

            if (z[k] >= k) {

                if (2 * k > answer)
                    answer = 2 * k;
            }
        }
    }

    printf("%d\n", answer);

    return 0;
}
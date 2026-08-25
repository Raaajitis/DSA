#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int a[MAXN];
int inc[MAXN];
int dec[MAXN];

int lowerBound(int arr[], int size, int value) {

    int left = 0;
    int right = size;

    while (left < right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    /*
     * Calculate LIS ending at every index.
     */
    int tails[MAXN];
    int size = 0;

    for (int i = 0; i < n; i++) {

        int pos =
            lowerBound(tails, size, a[i]);

        tails[pos] = a[i];

        if (pos == size)
            size++;

        inc[i] = pos + 1;
    }

    /*
     * Calculate LDS starting at every index.
     *
     * We process from right to left and find
     * an increasing subsequence in terms of
     * reversed values/order.
     */
    size = 0;

    for (int i = n - 1; i >= 0; i--) {

        int pos =
            lowerBound(tails, size, a[i]);

        tails[pos] = a[i];

        if (pos == size)
            size++;

        dec[i] = pos + 1;
    }

    int longestMountain = 0;

    for (int i = 0; i < n; i++) {

        /*
         * i must have both an increasing and
         * decreasing side.
         */
        if (inc[i] > 1 && dec[i] > 1) {

            int length =
                inc[i] + dec[i] - 1;

            if (length > longestMountain)
                longestMountain = length;
        }
    }

    if (longestMountain == 0)
        printf("-1\n");
    else
        printf("%d\n", n - longestMountain);

    return 0;
}
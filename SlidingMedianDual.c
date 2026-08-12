#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int a[MAXN];
int sorted[MAXN];
int bit[MAXN];

int compare(const void *x, const void *y) {
    return (*(int *)x - *(int *)y);
}

void update(int index, int value, int n) {

    while (index <= n) {
        bit[index] += value;
        index += index & -index;
    }
}

int query(int index) {

    int sum = 0;

    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }

    return sum;
}

/*
 * Find the position of the kth element.
 */
int kth(int k, int n) {

    int pos = 0;
    int step = 1;

    while ((step << 1) <= n)
        step <<= 1;

    for (; step > 0; step >>= 1) {

        int next = pos + step;

        if (next <= n && bit[next] < k) {
            pos = next;
            k -= bit[next];
        }
    }

    return pos + 1;
}

/*
 * Convert an original value into its compressed index.
 */
int lowerBound(int arr[], int n, int value) {

    int left = 0;
    int right = n;

    while (left < right) {

        int mid = (left + right) / 2;

        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return left + 1;
}

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sorted[i] = a[i];
    }

    /*
     * Coordinate compression
     */
    qsort(sorted, n, sizeof(int), compare);

    /*
     * Insert first window.
     */
    for (int i = 0; i < k; i++) {

        int pos = lowerBound(sorted, n, a[i]);

        update(pos, 1, n);
    }

    long long answer = 0;

    for (int left = 0; left <= n - k; left++) {

        /*
         * For an even-sized window, choose
         * the smaller of the two middle elements.
         *
         * Therefore kth = (k + 1) / 2.
         */
        int medianRank = (k + 1) / 2;

        int medianPos = kth(medianRank, n);
        int median = sorted[medianPos - 1];

        /*
         * Smallest element in the window.
         */
        int minPos = kth(1, n);
        int minimum = sorted[minPos - 1];

        /*
         * Largest element in the window.
         */
        int maxPos = kth(k, n);
        int maximum = sorted[maxPos - 1];

        long long leftDistance =
            (long long)median - minimum;

        long long rightDistance =
            (long long)maximum - median;

        int selected;

        if (leftDistance >= rightDistance)
            selected = minimum;
        else
            selected = maximum;

        answer += selected;

        /*
         * Remove outgoing element.
         */
        if (left + k < n) {

            int outgoing = a[left];

            int pos =
                lowerBound(sorted, n, outgoing);

            update(pos, -1, n);

            /*
             * Add incoming element.
             */
            int incoming = a[left + k];

            pos =
                lowerBound(sorted, n, incoming);

            update(pos, 1, n);
        }
    }

    printf("%lld\n", answer);

    return 0;
}
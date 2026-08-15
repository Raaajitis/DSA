#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int A[MAXN];
int B[MAXN];
int position[MAXN];
int bit[MAXN];

void update(int index, int n) {

    while (index <= n) {
        bit[index]++;
        index += index & -index;
    }
}

long long query(int index) {

    long long sum = 0;

    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }

    return sum;
}

int lowerBound(int arr[], int n, int value) {

    int left = 0;
    int right = n;

    while (left < right) {

        int mid = left + (right - left) / 2;

        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int compare(const void *x, const void *y) {

    int a = *(const int *)x;
    int b = *(const int *)y;

    if (a < b)
        return -1;

    if (a > b)
        return 1;

    return 0;
}

int main() {

    int n;
    long long k;

    scanf("%d %lld", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    /*
     * Coordinate compression.
     */
    int *sorted =
        malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        sorted[i] = B[i];

    qsort(sorted, n, sizeof(int), compare);

    /*
     * Position of each value in B.
     *
     * position[value's compressed rank] = index in B.
     */
    for (int i = 0; i < n; i++) {

        int rank =
            lowerBound(sorted, n, B[i]);

        position[rank] = i + 1;
    }

    /*
     * Convert A into positions in B.
     */
    for (int i = 0; i < n; i++) {

        int rank =
            lowerBound(sorted, n, A[i]);

        A[i] = position[rank];
    }

    /*
     * Count inversions.
     */
    long long inversions = 0;

    for (int i = n - 1; i >= 0; i--) {

        /*
         * Number of elements smaller than A[i]
         * already inserted.
         */
        inversions += query(A[i] - 1);

        update(A[i], n);
    }

    if (inversions <= k)
        printf("%lld\n", inversions);
    else
        printf("-1\n");

    free(sorted);

    return 0;
}
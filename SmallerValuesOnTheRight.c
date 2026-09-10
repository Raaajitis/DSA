#include <stdio.h>
#include <stdlib.h>

int compareLongLong(const void *first, const void *second) {
    long long a = *(const long long *)first;
    long long b = *(const long long *)second;

    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

void update(int *tree, int size, int index) {
    while (index <= size) {
        tree[index]++;
        index += index & -index;
    }
}

int query(const int *tree, int index) {
    int sum = 0;

    while (index > 0) {
        sum += tree[index];
        index -= index & -index;
    }

    return sum;
}

int findRank(const long long *sorted, int size, long long value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (sorted[middle] == value) {
            return middle + 1;
        }

        if (sorted[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    long long *array = malloc(n * sizeof(long long));
    long long *sorted = malloc(n * sizeof(long long));
    int *answer = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &array[i]);
        sorted[i] = array[i];
    }

    qsort(sorted, n, sizeof(long long), compareLongLong);

    /* Remove duplicates from the sorted array. */
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1]) {
            sorted[uniqueCount++] = sorted[i];
        }
    }

    int *fenwickTree = calloc(uniqueCount + 1, sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        int rank = findRank(sorted, uniqueCount, array[i]);

        /* Query ranks strictly smaller than the current rank. */
        answer[i] = query(fenwickTree, rank - 1);
        update(fenwickTree, uniqueCount, rank);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%s", answer[i], i == n - 1 ? "\n" : " ");
    }

    free(array);
    free(sorted);
    free(answer);
    free(fenwickTree);

    return 0;
}
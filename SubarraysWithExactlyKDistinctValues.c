#include <stdio.h>
#include <stdlib.h>

int compareLongLong(const void *first, const void *second) {
    long long a = *(const long long *)first;
    long long b = *(const long long *)second;

    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int findRank(
    const long long *sorted,
    int uniqueCount,
    long long value
) {
    int left = 0;
    int right = uniqueCount - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (sorted[middle] == value) {
            return middle;
        }

        if (sorted[middle] < value) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

long long countAtMost(
    const int *array,
    int n,
    int maximumDistinct,
    int uniqueCount
) {
    if (maximumDistinct < 0) {
        return 0;
    }

    int *frequency = calloc(uniqueCount, sizeof(int));

    int left = 0;
    int distinct = 0;
    long long subarrayCount = 0;

    for (int right = 0; right < n; right++) {
        if (frequency[array[right]] == 0) {
            distinct++;
        }

        frequency[array[right]]++;

        while (distinct > maximumDistinct) {
            frequency[array[left]]--;

            if (frequency[array[left]] == 0) {
                distinct--;
            }

            left++;
        }

        /*
         * Every subarray ending at right and beginning between
         * left and right contains at most maximumDistinct values.
         */
        subarrayCount += right - left + 1;
    }

    free(frequency);
    return subarrayCount;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    long long *original = malloc(n * sizeof(long long));
    long long *sorted = malloc(n * sizeof(long long));
    int *compressed = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &original[i]);
        sorted[i] = original[i];
    }

    qsort(sorted, n, sizeof(long long), compareLongLong);

    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1]) {
            sorted[uniqueCount++] = sorted[i];
        }
    }

    for (int i = 0; i < n; i++) {
        compressed[i] = findRank(
            sorted,
            uniqueCount,
            original[i]
        );
    }

    long long answer =
        countAtMost(compressed, n, k, uniqueCount) -
        countAtMost(compressed, n, k - 1, uniqueCount);

    printf("%lld\n", answer);

    free(original);
    free(sorted);
    free(compressed);

    return 0;
}
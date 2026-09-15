#include <stdio.h>
#include <stdlib.h>

int compareLongLong(const void *first, const void *second) {
    long long a = *(const long long *)first;
    long long b = *(const long long *)second;

    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);

    long long *values = malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        long long altitude;
        scanf("%lld", &altitude);

        values[i] = altitude - i;
    }

    qsort(values, n, sizeof(long long), compareLongLong);

    long long answer = 0;
    int groupStart = 0;

    while (groupStart < n) {
        int groupEnd = groupStart + 1;

        while (groupEnd < n &&
               values[groupEnd] == values[groupStart]) {
            groupEnd++;
        }

        long long groupSize = groupEnd - groupStart;
        answer += groupSize * (groupSize - 1) / 2;

        groupStart = groupEnd;
    }

    printf("%lld\n", answer);

    free(values);
    return 0;
}
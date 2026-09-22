#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long start;
    long long end;
    long long profit;
} Mission;

long long maximum(long long a, long long b) {
    return a > b ? a : b;
}

int compareMissions(const void *first, const void *second) {
    const Mission *a = first;
    const Mission *b = second;

    if (a->end < b->end) return -1;
    if (a->end > b->end) return 1;

    if (a->start < b->start) return -1;
    if (a->start > b->start) return 1;

    return 0;
}

int findLastCompatible(
    const Mission *missions,
    int right,
    long long startingTime
) {
    int left = 0;
    int answer = -1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (missions[middle].end < startingTime) {
            answer = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return answer;
}

int main(void) {
    int n;
    scanf("%d", &n);

    Mission *missions = malloc(n * sizeof(Mission));
    long long *dp = malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf(
            "%lld %lld %lld",
            &missions[i].start,
            &missions[i].end,
            &missions[i].profit
        );
    }

    qsort(
        missions,
        n,
        sizeof(Mission),
        compareMissions
    );

    for (int i = 0; i < n; i++) {
        int previous = findLastCompatible(
            missions,
            i - 1,
            missions[i].start
        );

        long long selectProfit = missions[i].profit;

        if (previous != -1) {
            selectProfit += dp[previous];
        }

        long long skipProfit = i > 0 ? dp[i - 1] : 0;

        dp[i] = maximum(selectProfit, skipProfit);
    }

    printf("%lld\n", dp[n - 1]);

    free(missions);
    free(dp);

    return 0;
}
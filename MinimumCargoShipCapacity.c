#include <stdio.h>
#include <stdlib.h>

int daysRequired(
    const long long *weights,
    int n,
    long long capacity
) {
    int days = 1;
    long long currentLoad = 0;

    for (int i = 0; i < n; i++) {
        if (currentLoad + weights[i] > capacity) {
            days++;
            currentLoad = weights[i];
        } else {
            currentLoad += weights[i];
        }
    }

    return days;
}

int main(void) {
    int n, allowedDays;
    scanf("%d %d", &n, &allowedDays);

    long long *weights = malloc(n * sizeof(long long));

    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &weights[i]);

        if (weights[i] > left) {
            left = weights[i];
        }

        right += weights[i];
    }

    while (left < right) {
        long long middle = left + (right - left) / 2;

        if (daysRequired(weights, n, middle) <= allowedDays) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }

    printf("%lld\n", left);

    free(weights);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

long long absoluteDifference(long long a, long long b) {
    return a >= b ? a - b : b - a;
}

int main(void) {
    int n;
    long long k;

    scanf("%d %lld", &n, &k);

    long long *height = malloc(n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &height[i]);
    }

    int left = 0;
    int maximumLength = 1;
    long long currentCost = 0;

    for (int right = 1; right < n; right++) {
        currentCost += absoluteDifference(
            height[right],
            height[right - 1]
        );

        while (currentCost > k && left < right) {
            currentCost -= absoluteDifference(
                height[left + 1],
                height[left]
            );

            left++;
        }

        int currentLength = right - left + 1;

        if (currentLength > maximumLength) {
            maximumLength = currentLength;
        }
    }

    printf("%d\n", maximumLength);

    free(height);
    return 0;
}
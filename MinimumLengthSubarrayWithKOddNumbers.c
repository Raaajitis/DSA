#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int *oddPositions = malloc(n * sizeof(int));
    int oddCount = 0;

    for (int i = 0; i < n; i++) {
        long long value;
        scanf("%lld", &value);

        /* Works correctly for both positive and negative odd values. */
        if (value % 2 != 0) {
            oddPositions[oddCount++] = i;
        }
    }

    if (oddCount < k) {
        printf("-1\n");
        free(oddPositions);
        return 0;
    }

    int minimumLength = INT_MAX;

    for (int left = 0; left + k - 1 < oddCount; left++) {
        int right = left + k - 1;
        int length = oddPositions[right] - oddPositions[left] + 1;

        if (length < minimumLength) {
            minimumLength = length;
        }
    }

    printf("%d\n", minimumLength);

    free(oddPositions);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long *array = malloc(n * sizeof(long long));

    long long totalEven = 0;
    long long totalOdd = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &array[i]);

        if (i % 2 == 0) {
            totalEven += array[i];
        } else {
            totalOdd += array[i];
        }
    }

    long long leftEven = 0;
    long long leftOdd = 0;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        /*
         * Remove the current element from the right-side totals.
         */
        if (i % 2 == 0) {
            totalEven -= array[i];
        } else {
            totalOdd -= array[i];
        }

        /*
         * Right-side parities are reversed after removal.
         */
        long long newEvenSum = leftEven + totalOdd;
        long long newOddSum = leftOdd + totalEven;

        if (newEvenSum == newOddSum) {
            answer++;
        }

        /*
         * Add the current element to the original left-side sums
         * for the next iteration.
         */
        if (i % 2 == 0) {
            leftEven += array[i];
        } else {
            leftOdd += array[i];
        }
    }

    printf("%d\n", answer);

    free(array);
    return 0;
}
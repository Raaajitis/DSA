#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long value;
    long long count;
} StackEntry;

int main(void) {
    int n;
    scanf("%d", &n);

    StackEntry *stack = malloc(n * sizeof(StackEntry));
    int top = 0;

    long long endingSum = 0;
    long long totalSum = 0;

    for (int i = 0; i < n; i++) {
        long long current;
        scanf("%lld", &current);

        long long count = 1;

        /*
         * Remove values that are greater than or equal to current.
         * Their subarrays will now have current as their minimum.
         */
        while (top > 0 &&
               stack[top - 1].value >= current) {
            endingSum -=
                stack[top - 1].value *
                stack[top - 1].count;

            count += stack[top - 1].count;
            top--;
        }

        stack[top].value = current;
        stack[top].count = count;
        top++;

        endingSum += current * count;

        /*
         * endingSum is the sum of minimums of all subarrays
         * ending at the current position.
         */
        totalSum += endingSum;
    }

    printf("%lld\n", totalSum);

    free(stack);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long *height = malloc(n * sizeof(long long));
    long long *answer = malloc(n * sizeof(long long));
    int *stack = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &height[i]);
        answer[i] = -1;
    }

    int top = -1;

    /* Traverse from right to left twice. */
    for (int i = 2 * n - 1; i >= 0; i--) {
        int index = i % n;

        while (top >= 0 &&
               height[stack[top]] <= height[index]) {
            top--;
        }

        /* Record answers only during the second logical pass. */
        if (i < n && top >= 0) {
            answer[index] = height[stack[top]];
        }

        /*
         * Keeping only n elements is sufficient. Equal or shorter
         * towers were already removed by the while loop.
         */
        stack[++top] = index;
    }

    for (int i = 0; i < n; i++) {
        printf("%lld%s", answer[i], i == n - 1 ? "\n" : " ");
    }

    free(height);
    free(answer);
    free(stack);

    return 0;
}
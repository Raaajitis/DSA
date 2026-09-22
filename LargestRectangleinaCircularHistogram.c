#include <stdio.h>
#include <stdlib.h>

long long minimum(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n;
    scanf("%d", &n);

    long long *height = malloc(n * sizeof(long long));
    int *stack = malloc((2 * n + 1) * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &height[i]);
    }

    int top = 0;
    long long maximumArea = 0;

    /*
     * Process 2N bars plus one virtual zero-height bar
     * to empty the stack.
     */
    for (int i = 0; i <= 2 * n; i++) {
        long long currentHeight =
            i == 2 * n ? 0 : height[i % n];

        while (top > 0) {
            int topIndex = stack[top - 1];
            long long topHeight = height[topIndex % n];

            if (topHeight < currentHeight) {
                break;
            }

            top--;

            int leftBoundary =
                top == 0 ? -1 : stack[top - 1];

            long long width = i - leftBoundary - 1;

            /*
             * A circular rectangle cannot contain more than N bars.
             */
            width = minimum(width, n);

            long long area = topHeight * width;

            if (area > maximumArea) {
                maximumArea = area;
            }
        }

        if (i < 2 * n) {
            stack[top++] = i;
        }
    }

    printf("%lld\n", maximumArea);

    free(height);
    free(stack);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    long long *stack = malloc(n * sizeof(long long));
    int top = 0;

    for (int i = 0; i < n; i++) {
        long long power;
        scanf("%lld", &power);

        stack[top++] = power;

        while (top >= 2 && stack[top - 1] == stack[top - 2]) {
            long long fusedPower = stack[top - 1] + 1;

            /* Remove the two equal crystals. */
            top -= 2;

            /* Insert the fused crystal. */
            stack[top++] = fusedPower;
        }
    }

    printf("%d\n", top);

    for (int i = 0; i < top; i++) {
        printf("%lld%s", stack[i], i == top - 1 ? "\n" : " ");
    }

    free(stack);
    return 0;
}
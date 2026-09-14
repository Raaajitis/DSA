#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long height;
    int count;
} TowerGroup;

int main(void) {
    int n;
    scanf("%d", &n);

    TowerGroup *stack = malloc(n * sizeof(TowerGroup));
    int top = 0;
    long long visiblePairs = 0;

    for (int i = 0; i < n; i++) {
        long long currentHeight;
        scanf("%lld", &currentHeight);

        /*
         * Every shorter group on top can see the current tower.
         */
        while (top > 0 &&
               stack[top - 1].height < currentHeight) {
            visiblePairs += stack[top - 1].count;
            top--;
        }

        if (top == 0) {
            stack[top++] = (TowerGroup){currentHeight, 1};
        } else if (stack[top - 1].height == currentHeight) {
            /*
             * The current tower sees all equal-height towers.
             */
            int equalCount = stack[top - 1].count;
            visiblePairs += equalCount;

            stack[top - 1].count++;

            /*
             * If a taller tower exists behind the equal group,
             * the current tower can see it too.
             */
            if (top > 1) {
                visiblePairs++;
            }
        } else {
            /*
             * The stack's top is taller than the current tower.
             */
            visiblePairs++;
            stack[top++] = (TowerGroup){currentHeight, 1};
        }
    }

    printf("%lld\n", visiblePairs);

    free(stack);
    return 0;
}
#include <stdio.h>

void visiblePeople(int heights[], int n) {

    int stack[n];
    int result[n];

    int top = -1;

    for (int i = n - 1; i >= 0; i--) {

        int count = 0;

        // All shorter people popped are visible
        while (top >= 0 &&
               heights[i] > stack[top]) {

            top--;
            count++;
        }

        /*
         * If someone remains, the first
         * taller person is also visible.
         */
        if (top >= 0) {
            count++;
        }

        result[i] = count;

        stack[++top] = heights[i];
    }

    printf("Visible people to the right:\n");

    for (int i = 0; i < n; i++) {

        printf("%d -> %d\n",
               heights[i],
               result[i]);
    }
}

int main() {

    int heights[] = {
        10, 6, 8, 5, 11, 9
    };

    int n =
        sizeof(heights) / sizeof(heights[0]);

    visiblePeople(heights, n);

    return 0;
}
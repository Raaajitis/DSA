#include <stdio.h>
#include <stdlib.h>

void asteroidCollision(int asteroids[], int n) {

    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {

        int current = asteroids[i];
        int destroyed = 0;

        while (top >= 0 &&
               stack[top] > 0 &&
               current < 0) {

            if (stack[top] < abs(current)) {

                // Stack asteroid is smaller
                top--;

            } else if (stack[top] == abs(current)) {

                // Both are destroyed
                top--;
                destroyed = 1;
                break;

            } else {

                // Current asteroid is smaller
                destroyed = 1;
                break;
            }
        }

        if (!destroyed) {
            stack[++top] = current;
        }
    }

    if (top == -1) {

        printf("No asteroids remain.\n");

    } else {

        printf("Remaining asteroids: ");

        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }

        printf("\n");
    }
}

int main() {

    int asteroids[] = {10, 2, -5};

    int n = sizeof(asteroids) / sizeof(asteroids[0]);

    asteroidCollision(asteroids, n);

    return 0;
}
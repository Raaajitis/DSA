#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long maximum(long long a, long long b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    const long long NEGATIVE_INFINITY = LLONG_MIN / 4;

    long long *withoutShield = malloc(m * sizeof(long long));
    long long *withShield = malloc(m * sizeof(long long));

    for (int column = 0; column < m; column++) {
        withoutShield[column] = NEGATIVE_INFINITY;
        withShield[column] = NEGATIVE_INFINITY;
    }

    for (int row = 0; row < n; row++) {
        for (int column = 0; column < m; column++) {
            long long value;
            scanf("%lld", &value);

            if (row == 0 && column == 0) {
                withoutShield[column] = value;
                withShield[column] = 0;
                continue;
            }

            long long previousWithout = NEGATIVE_INFINITY;
            long long previousWith = NEGATIVE_INFINITY;

            /* State coming from above. */
            if (row > 0) {
                previousWithout = withoutShield[column];
                previousWith = withShield[column];
            }

            /* State coming from the left. */
            if (column > 0) {
                previousWithout = maximum(
                    previousWithout,
                    withoutShield[column - 1]
                );

                previousWith = maximum(
                    previousWith,
                    withShield[column - 1]
                );
            }

            long long newWithout = previousWithout + value;

            long long continueAfterShield =
                previousWith + value;

            long long activateShieldHere =
                previousWithout;

            long long newWith = maximum(
                continueAfterShield,
                activateShieldHere
            );

            withoutShield[column] = newWithout;
            withShield[column] = newWith;
        }
    }

    long long answer = maximum(
        withoutShield[m - 1],
        withShield[m - 1]
    );

    printf("%lld\n", answer);

    free(withoutShield);
    free(withShield);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

long long absoluteValue(long long value) {
    return value < 0 ? -value : value;
}

int main(void) {
    int n;
    scanf("%d", &n);

    char *corridor = malloc((n + 1) * sizeof(char));
    scanf("%s", corridor);

    long long *transformed = malloc(n * sizeof(long long));
    int robotCount = 0;

    for (int position = 0; position < n; position++) {
        if (corridor[position] == '1') {
            transformed[robotCount] =
                (long long)position - robotCount;

            robotCount++;
        }
    }

    if (robotCount <= 1) {
        printf("0\n");

        free(corridor);
        free(transformed);
        return 0;
    }

    /*
     * Robot positions are already sorted, so transformed positions
     * are also non-decreasing.
     */
    long long median = transformed[robotCount / 2];
    long long minimumMoves = 0;

    for (int i = 0; i < robotCount; i++) {
        minimumMoves += absoluteValue(
            transformed[i] - median
        );
    }

    printf("%lld\n", minimumMoves);

    free(corridor);
    free(transformed);

    return 0;
}
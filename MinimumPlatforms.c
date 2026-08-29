#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {

    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main() {

    int n;
    scanf("%d", &n);

    int *arrival =
        malloc(n * sizeof(int));

    int *departure =
        malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &arrival[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &departure[i]);

    qsort(arrival, n, sizeof(int), compare);
    qsort(departure, n, sizeof(int), compare);

    int i = 0;
    int j = 0;

    int platforms = 0;
    int maximum = 0;

    while (i < n && j < n) {

        /*
         * A train arrives before the earliest
         * currently available platform.
         */
        if (arrival[i] < departure[j]) {

            platforms++;
            i++;

            if (platforms > maximum)
                maximum = platforms;
        }

        /*
         * A train has departed, so its platform
         * becomes available.
         *
         * >= is intentional: simultaneous
         * departure and arrival can reuse a platform.
         */
        else {

            platforms--;
            j++;
        }
    }

    printf("%d\n", maximum);

    free(arrival);
    free(departure);

    return 0;
}
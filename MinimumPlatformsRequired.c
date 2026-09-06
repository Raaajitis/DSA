#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int minPlatforms(int arrival[], int departure[], int n) {
    qsort(arrival, n, sizeof(int), compare);
    qsort(departure, n, sizeof(int), compare);

    int platforms = 0;
    int maxPlatforms = 0;

    int i = 0;
    int j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            i++;

            if (platforms > maxPlatforms)
                maxPlatforms = platforms;
        } else {
            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {
    int arrival[] = {900, 940, 950, 1100, 1500, 1800};
    int departure[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n = sizeof(arrival) / sizeof(arrival[0]);

    printf("Minimum Platforms: %d\n",
           minPlatforms(arrival, departure, n));

    return 0;
}
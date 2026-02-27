#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findPlatforms(int arr[], int dep[], int n) {
    // Sort arrival and departure times
    qsort(arr, n, sizeof(int), compare);
    qsort(dep, n, sizeof(int), compare);

    int plat_needed = 1, max_platforms = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }

        if (plat_needed > max_platforms)
            max_platforms = plat_needed;
    }

    return max_platforms;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum Platforms Required: %d\n",
           findPlatforms(arr, dep, n));

    return 0;
}
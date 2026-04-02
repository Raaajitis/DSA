#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int findPlatforms(int arr[], int dep[], int n) {

    qsort(arr, n, sizeof(int), compare);
    qsort(dep, n, sizeof(int), compare);

    int plat = 1, result = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {

        if (arr[i] <= dep[j]) {
            plat++;
            i++;
        } else {
            plat--;
            j++;
        }

        if (plat > result)
            result = plat;
    }

    return result;
}

int main() {

    int arr[] = {900,940,950,1100,1500,1800};
    int dep[] = {910,1200,1120,1130,1900,2000};

    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Minimum Platforms: %d\n",
           findPlatforms(arr,dep,n));

    return 0;
}
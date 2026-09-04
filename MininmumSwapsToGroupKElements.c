#include <stdio.h>

int minSwaps(int arr[], int n, int k) {
    int good = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k)
            good++;
    }

    if (good <= 1)
        return 0;

    int currentGood = 0;

    for (int i = 0; i < good; i++) {
        if (arr[i] <= k)
            currentGood++;
    }

    int maxGood = currentGood;

    for (int i = good; i < n; i++) {
        if (arr[i] <= k)
            currentGood++;

        if (arr[i - good] <= k)
            currentGood--;

        if (currentGood > maxGood)
            maxGood = currentGood;
    }

    return good - maxGood;
}

int main() {
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Minimum Swaps: %d\n", minSwaps(arr, n, k));

    return 0;
}
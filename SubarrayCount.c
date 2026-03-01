#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int countSubarrays(int arr[], int n, int K) {
    int prefixSum = 0;
    int count = 0;

    // Hash array for prefix frequencies
    int *hash = (int *)calloc(2*MAX + 1, sizeof(int));
    int offset = MAX;

    hash[offset] = 1;  // Base case: sum = 0

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum - K + offset >= 0 &&
            prefixSum - K + offset < 2*MAX + 1)
            count += hash[prefixSum - K + offset];

        hash[prefixSum + offset]++;
    }

    free(hash);
    return count;
}

int main() {
    int arr[] = {1, 2, 3};
    int K = 3;
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Number of Subarrays: %d\n",
           countSubarrays(arr, n, K));

    return 0;
}
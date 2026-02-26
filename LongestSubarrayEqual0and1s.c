#include <stdio.h>
#include <stdlib.h>

int findMaxLength(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Create hash array (size = 2*n + 1)
    int *hash = (int *)malloc((2*n + 1) * sizeof(int));

    // Initialize with -2 (means not visited)
    for (int i = 0; i < 2*n + 1; i++)
        hash[i] = -2;

    // Offset to handle negative index
    int offset = n;

    hash[offset] = -1; // sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            sum += -1;
        else
            sum += 1;

        if (hash[sum + offset] != -2) {
            int length = i - hash[sum + offset];
            if (length > maxLen)
                maxLen = length;
        } else {
            hash[sum + offset] = i;
        }
    }

    free(hash);
    return maxLen;
}

int main() {
    int arr[] = {0, 1, 0, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Longest Subarray Length: %d\n", findMaxLength(arr, n));

    return 0;
}
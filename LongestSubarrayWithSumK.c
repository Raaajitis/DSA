#include <stdio.h>

#define MAX 1000

int longestSubarraySumK(int arr[], int n, int k) {

    int prefixValues[MAX];
    int prefixIndices[MAX];

    int count = 0;
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < n; i++) {

        prefixSum += arr[i];

        // Subarray starting from index 0
        if (prefixSum == k) {

            if (i + 1 > maxLength) {
                maxLength = i + 1;
            }
        }

        int required = prefixSum - k;

        // Search for required prefix sum
        for (int j = 0; j < count; j++) {

            if (prefixValues[j] == required) {

                int length = i - prefixIndices[j];

                if (length > maxLength) {
                    maxLength = length;
                }

                break;
            }
        }

        // Store only the first occurrence
        int alreadyExists = 0;

        for (int j = 0; j < count; j++) {

            if (prefixValues[j] == prefixSum) {
                alreadyExists = 1;
                break;
            }
        }

        if (!alreadyExists) {

            prefixValues[count] = prefixSum;
            prefixIndices[count] = i;

            count++;
        }
    }

    return maxLength;
}

int main() {

    int arr[] = {10, 5, 2, 7, 1, 9};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 15;

    int result = longestSubarraySumK(arr, n, k);

    printf("Length of longest subarray: %d\n", result);

    return 0;
}
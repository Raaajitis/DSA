#include <stdio.h>

#define MAX 1000

int countSubarrays(int arr[], int n, int k) {

    int sums[MAX];
    int frequencies[MAX];

    int stored = 1;

    // Prefix sum 0 exists once before array starts
    sums[0] = 0;
    frequencies[0] = 1;

    int prefixSum = 0;
    int answer = 0;

    for (int i = 0; i < n; i++) {

        prefixSum += arr[i];

        int required = prefixSum - k;

        // Find frequency of required prefix
        for (int j = 0; j < stored; j++) {

            if (sums[j] == required) {

                answer += frequencies[j];
                break;
            }
        }

        // Store/update current prefix sum
        int found = 0;

        for (int j = 0; j < stored; j++) {

            if (sums[j] == prefixSum) {

                frequencies[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {

            sums[stored] = prefixSum;
            frequencies[stored] = 1;

            stored++;
        }
    }

    return answer;
}

int main() {

    int arr[] = {1, 1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    int result = countSubarrays(arr, n, k);

    printf("Number of subarrays with sum %d: %d\n",
           k, result);

    return 0;
}
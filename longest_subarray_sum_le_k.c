// File: longest_subarray_sum_le_k.c
#include <stdio.h>
#include <stdlib.h>

int longestSubarray(int arr[], int n, int K) {
    long prefix[n+1];
    prefix[0] = 0;

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i-1] + arr[i-1];

    // Array of prefix sums and their indices
    struct Node {
        long val;
        int idx;
    };
    struct Node temp[n+1];

    for (int i = 0; i <= n; i++) {
        temp[i].val = prefix[i];
        temp[i].idx = i;
    }

    // Sort prefix sums
    for (int i = 0; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            if (temp[j].val < temp[i].val) {
                struct Node t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }

    int maxLen = 0;

    // Try all prefix sums
    for (int i = 0; i <= n; i++) {
        long target = prefix[i] - K;

        // Binary search manually
        int low = 0, high = n, best = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (temp[mid].val >= target) {
                best = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        if (best != -1) {
            int idx = temp[best].idx;
            if (idx <= i)
                maxLen = (maxLen > (i - idx)) ? maxLen : (i - idx);
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {2, -1, 3, -2, 4};
    int K = 3;
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Longest Length: %d\n", longestSubarray(arr, n, K));
    return 0;
}
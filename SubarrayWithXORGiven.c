#include <stdio.h>

#define MAX 1000

int countSubarrays(int arr[], int n, int k) {

    int xor = 0, count = 0;
    int freq[1000] = {0};

    freq[0] = 1;

    for (int i = 0; i < n; i++) {

        xor ^= arr[i];

        if (freq[xor ^ k] > 0)
            count += freq[xor ^ k];

        freq[xor]++;
    }

    return count;
}

int main() {

    int arr[] = {4,2,2,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    printf("Count: %d\n", countSubarrays(arr,n,k));

    return 0;
}
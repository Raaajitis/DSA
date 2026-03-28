#include <stdio.h>

#define MAX 1000

int subarraySum(int arr[], int n, int k) {

    int count = 0, sum = 0;
    int freq[MAX] = {0};

    freq[0] = 1;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum - k >= 0 && freq[sum - k])
            count += freq[sum - k];

        freq[sum]++;

    }

    return count;
}

int main() {

    int arr[] = {1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    printf("Count: %d\n", subarraySum(arr,n,k));

    return 0;
}
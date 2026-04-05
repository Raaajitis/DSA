#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int exists(int hash[], int x) {
    return hash[x] == 1;
}

int longestConsecutive(int arr[], int n) {

    int hash[MAX] = {0};

    for (int i = 0; i < n; i++)
        hash[arr[i]] = 1;

    int maxLen = 0;

    for (int i = 0; i < n; i++) {

        if (!exists(hash, arr[i] - 1)) {

            int current = arr[i];
            int length = 1;

            while (exists(hash, current + 1)) {
                current++;
                length++;
            }

            if (length > maxLen)
                maxLen = length;
        }
    }

    return maxLen;
}

int main() {

    int arr[] = {100,4,200,1,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Longest Sequence: %d\n",
           longestConsecutive(arr,n));

    return 0;
}
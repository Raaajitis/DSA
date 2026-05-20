#include <stdio.h>

#define MAX 100

void shadowClone(int arr[], int n) {

    int freq[MAX] = {0};

    for (int i = 0; i < n; i++) {

        freq[arr[i]]++;

        for (int j = 0; j < freq[arr[i]]; j++)
            printf("%d ", arr[i]);
    }
}

int main() {

    int arr[] = {2,3,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    shadowClone(arr,n);

    return 0;
}
#include <stdio.h>

#define MAX 100

int main() {

    int arr[] = {1,2,1,3};
    int n = 4;
    int k = 2;

    int freq[MAX] = {0};
    int output[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {

        output[size++] = arr[i];

        freq[arr[i]]++;

        if (freq[arr[i]] > 1) {

            // delayed echo
            output[size + k - 1] = arr[i];
        }
    }

    for (int i = 0; i < size + k; i++) {

        if (output[i] != 0)
            printf("%d ", output[i]);
    }

    return 0;
}
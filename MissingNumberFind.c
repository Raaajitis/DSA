#include <stdio.h>

int findMissing(int arr[], int n) {

    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i <= n; i++)
        xor1 ^= i;

    for (int i = 0; i < n; i++)
        xor2 ^= arr[i];

    return xor1 ^ xor2;
}

int main() {

    int arr[] = {3, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Missing Number: %d\n", findMissing(arr, n));

    return 0;
}
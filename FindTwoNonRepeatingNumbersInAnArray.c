#include <stdio.h>

void findTwoUnique(int arr[], int n) {

    int xorValue = 0;

    // XOR all elements
    for (int i = 0; i < n; i++) {
        xorValue ^= arr[i];
    }

    // Isolate rightmost set bit
    int setBit = xorValue & -xorValue;

    int first = 0;
    int second = 0;

    // Divide elements into two groups
    for (int i = 0; i < n; i++) {

        if (arr[i] & setBit) {

            first ^= arr[i];

        } else {

            second ^= arr[i];
        }
    }

    printf("Two non-repeating numbers: %d %d\n",
           first, second);
}

int main() {

    int arr[] = {2, 4, 7, 9, 2, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    findTwoUnique(arr, n);

    return 0;
}
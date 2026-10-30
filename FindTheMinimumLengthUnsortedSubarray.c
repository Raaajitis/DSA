#include <stdio.h>

void findUnsortedSubarray(int arr[], int n) {

    if (n <= 1) {
        printf("Array is already sorted.\n");
        return;
    }

    int end = -1;
    int maxSeen = arr[0];

    // Find right boundary
    for (int i = 1; i < n; i++) {

        if (arr[i] < maxSeen) {
            end = i;
        }
        else {
            maxSeen = arr[i];
        }
    }

    // Array is already sorted
    if (end == -1) {

        printf("Array is already sorted.\n");
        printf("Length of unsorted subarray: 0\n");

        return;
    }

    int start = 0;
    int minSeen = arr[n - 1];

    // Find left boundary
    for (int i = n - 2; i >= 0; i--) {

        if (arr[i] > minSeen) {
            start = i;
        }
        else {
            minSeen = arr[i];
        }
    }

    printf("Start index: %d\n", start);
    printf("End index: %d\n", end);

    printf("Length of unsorted subarray: %d\n",
           end - start + 1);
}

int main() {

    int arr[] = {2, 6, 4, 8, 10, 9, 15};

    int n = sizeof(arr) / sizeof(arr[0]);

    findUnsortedSubarray(arr, n);

    return 0;
}
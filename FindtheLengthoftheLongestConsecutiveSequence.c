#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y)
        return -1;
    if (x > y)
        return 1;

    return 0;
}

int longestConsecutive(int arr[], int n) {

    if (n == 0) {
        return 0;
    }

    qsort(arr, n, sizeof(int), compare);

    int currentLength = 1;
    int maxLength = 1;

    for (int i = 1; i < n; i++) {

        if (arr[i] == arr[i - 1] + 1) {

            currentLength++;

        } else if (arr[i] == arr[i - 1]) {

            // Ignore duplicate elements

        } else {

            currentLength = 1;
        }

        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main() {

    int arr[] = {100, 4, 200, 1, 3, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestConsecutive(arr, n);

    printf("Length of longest consecutive sequence: %d\n", result);

    return 0;
}
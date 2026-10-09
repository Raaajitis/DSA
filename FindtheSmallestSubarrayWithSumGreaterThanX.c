#include <stdio.h>

int smallestSubarray(int arr[], int n, int x) {

    int start = 0;
    int currentSum = 0;
    int minLength = n + 1;

    for (int end = 0; end < n; end++) {

        currentSum += arr[end];

        while (currentSum > x) {

            int currentLength = end - start + 1;

            if (currentLength < minLength) {
                minLength = currentLength;
            }

            currentSum -= arr[start];
            start++;
        }
    }

    if (minLength == n + 1) {
        return 0;
    }

    return minLength;
}

int main() {

    int arr[] = {1, 4, 45, 6, 10, 19};

    int n = sizeof(arr) / sizeof(arr[0]);

    int x = 51;

    int result = smallestSubarray(arr, n, x);

    if (result == 0) {
        printf("No valid subarray exists.\n");
    }
    else {
        printf("Smallest subarray length: %d\n", result);
    }

    return 0;
}
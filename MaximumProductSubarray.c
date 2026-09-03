#include <stdio.h>

int maxProduct(int arr[], int n) {
    int maxEnding = arr[0];
    int minEnding = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            int temp = maxEnding;
            maxEnding = minEnding;
            minEnding = temp;
        }

        if (arr[i] > maxEnding * arr[i])
            maxEnding = arr[i];
        else
            maxEnding = maxEnding * arr[i];

        if (arr[i] < minEnding * arr[i])
            minEnding = arr[i];
        else
            minEnding = minEnding * arr[i];

        if (maxEnding > result)
            result = maxEnding;
    }

    return result;
}

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum Product: %d\n", maxProduct(arr, n));

    return 0;
}
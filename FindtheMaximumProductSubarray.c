#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maximumProductSubarray(int arr[], int n) {

    if (n == 0) {
        return 0;
    }

    int currentMax = arr[0];
    int currentMin = arr[0];

    int answer = arr[0];

    for (int i = 1; i < n; i++) {

        // Negative number reverses max and min
        if (arr[i] < 0) {

            int temp = currentMax;
            currentMax = currentMin;
            currentMin = temp;
        }

        currentMax =
            max(arr[i],
                currentMax * arr[i]);

        currentMin =
            min(arr[i],
                currentMin * arr[i]);

        answer = max(answer, currentMax);
    }

    return answer;
}

int main() {

    int arr[] = {-2, 3, -4};

    int n = sizeof(arr) / sizeof(arr[0]);

    int result =
        maximumProductSubarray(arr, n);

    printf("Maximum product: %d\n", result);

    return 0;
}
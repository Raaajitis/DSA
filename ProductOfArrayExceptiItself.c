#include <stdio.h>

void productExceptSelf(int arr[], int n) {

    int result[n];

    // Product of elements to the left
    int prefix = 1;

    for (int i = 0; i < n; i++) {

        result[i] = prefix;

        prefix = prefix * arr[i];
    }

    // Product of elements to the right
    int suffix = 1;

    for (int i = n - 1; i >= 0; i--) {

        result[i] = result[i] * suffix;

        suffix = suffix * arr[i];
    }

    printf("Result: ");

    for (int i = 0; i < n; i++) {

        printf("%d ", result[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {1, 2, 3, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    productExceptSelf(arr, n);

    return 0;
}
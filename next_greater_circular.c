#include <stdio.h>

void nextGreater(int arr[], int n) {
    int result[n];
    int stack[2 * n];
    int top = -1;

    // Initially, all answers are -1
    for (int i = 0; i < n; i++)
        result[i] = -1;

    // Traverse twice because the array is circular
    for (int i = 2 * n - 1; i >= 0; i--) {

        int index = i % n;

        // Remove elements that cannot be the next greater
        while (top >= 0 && stack[top] <= arr[index])
            top--;

        // Only assign result during the first traversal
        if (i < n && top >= 0)
            result[index] = stack[top];

        stack[++top] = arr[index];
    }

    printf("Next Greater Elements: ");

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");
}

int main() {
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreater(arr, n);

    return 0;
}
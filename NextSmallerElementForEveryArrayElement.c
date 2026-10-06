#include <stdio.h>

void nextSmallerElement(int arr[], int n) {

    int stack[n];
    int result[n];

    int top = -1;

    for (int i = n - 1; i >= 0; i--) {

        // Remove elements that are not smaller
        while (top != -1 && stack[top] >= arr[i]) {
            top--;
        }

        // If stack is empty, no smaller element exists
        if (top == -1) {
            result[i] = -1;
        }
        else {
            result[i] = stack[top];
        }

        // Push current element
        stack[++top] = arr[i];
    }

    printf("Next smaller elements:\n");

    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }
}

int main() {

    int arr[] = {4, 8, 5, 2, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    nextSmallerElement(arr, n);

    return 0;
}
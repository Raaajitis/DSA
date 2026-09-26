#include <stdio.h>

void nextGreaterCircular(int arr[], int n) {

    int result[n];
    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        result[i] = -1;
    }

    for (int i = 0; i < 2 * n; i++) {

        int index = i % n;

        while (top != -1 &&
               arr[index] > arr[stack[top]]) {

            result[stack[top]] = arr[index];
            top--;
        }

        if (i < n) {
            stack[++top] = index;
        }
    }

    printf("Next greater elements: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterCircular(arr, n);

    return 0;
}
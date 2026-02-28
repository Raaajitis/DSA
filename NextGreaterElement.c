#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void nextGreaterElement(int arr[], int n) {
    int stack[MAX];
    int top = -1;
    int result[n];

    for (int i = n - 1; i >= 0; i--) {

        while (top >= 0 && stack[top] <= arr[i])
            top--;

        if (top < 0)
            result[i] = -1;
        else
            result[i] = stack[top];

        stack[++top] = arr[i];
    }

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    nextGreaterElement(arr, n);

    return 0;
}
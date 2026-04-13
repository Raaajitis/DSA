#include <stdio.h>

#define MAX 1000

void nextGreater(int arr[], int n) {

    int result[n];
    int stack[MAX], top = -1;

    for (int i = 0; i < n; i++)
        result[i] = -1;

    for (int i = 0; i < 2*n; i++) {

        int idx = i % n;

        while (top != -1 && arr[stack[top]] < arr[idx]) {
            result[stack[top--]] = arr[idx];
        }

        if (i < n)
            stack[++top] = idx;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
}

int main() {

    int arr[] = {1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    nextGreater(arr, n);

    return 0;
}
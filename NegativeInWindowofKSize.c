#include <stdio.h>

void firstNegativeInWindow(int arr[], int n, int k) {

    int queue[n];
    int front = 0;
    int rear = -1;

    for (int i = 0; i < n; i++) {

        // Remove indices which are outside the current window
        while (front <= rear && queue[front] <= i - k) {
            front++;
        }

        // Store index if current element is negative
        if (arr[i] < 0) {
            queue[++rear] = i;
        }

        // Start printing when first complete window is formed
        if (i >= k - 1) {

            if (front <= rear) {
                printf("%d ", arr[queue[front]]);
            }
            else {
                printf("0 ");
            }
        }
    }
}

int main() {

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    printf("First negative number in every window:\n");

    firstNegativeInWindow(arr, n, k);

    return 0;
}
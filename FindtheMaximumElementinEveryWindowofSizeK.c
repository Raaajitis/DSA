#include <stdio.h>

void maxInWindows(int arr[], int n, int k) {

    if (k <= 0 || k > n) {
        printf("Invalid window size.\n");
        return;
    }

    int deque[n];

    int front = 0;
    int rear = -1;

    printf("Maximum elements: ");

    for (int i = 0; i < n; i++) {

        // Remove indices outside current window
        while (front <= rear &&
               deque[front] <= i - k) {

            front++;
        }

        // Remove smaller elements from the back
        while (front <= rear &&
               arr[deque[rear]] <= arr[i]) {

            rear--;
        }

        // Add current index
        deque[++rear] = i;

        // A complete window has been formed
        if (i >= k - 1) {

            printf("%d ", arr[deque[front]]);
        }
    }

    printf("\n");
}

int main() {

    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 3;

    maxInWindows(arr, n, k);

    return 0;
}
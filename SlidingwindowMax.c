#include <stdio.h>

#define MAX 1000

void slidingWindowMax(int arr[], int n, int k) {

    int dq[MAX];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {

        // Remove out-of-window
        if (front <= rear && dq[front] <= i - k)
            front++;

        // Remove smaller elements
        while (front <= rear && arr[dq[rear]] < arr[i])
            rear--;

        dq[++rear] = i;

        if (i >= k - 1)
            printf("%d ", arr[dq[front]]);
    }
}

int main() {

    int arr[] = {1,3,-1,-3,5,3,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    slidingWindowMax(arr, n, k);

    return 0;
}
#include <stdio.h>
#include <limits.h>

int shortestSubarray(int arr[], int n, long long k) {

    long long prefix[n + 1];

    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int deque[n + 1];

    int front = 0;
    int rear = 0;

    int minLength = INT_MAX;

    for (int i = 0; i <= n; i++) {

        // Check whether a valid subarray exists
        while (front < rear &&
               prefix[i] - prefix[deque[front]] >= k) {

            int length = i - deque[front];

            if (length < minLength) {
                minLength = length;
            }

            front++;
        }

        // Remove useless prefix sums
        while (front < rear &&
               prefix[i] <= prefix[deque[rear - 1]]) {

            rear--;
        }

        deque[rear++] = i;
    }

    if (minLength == INT_MAX) {
        return -1;
    }

    return minLength;
}

int main() {

    int arr[] = {84, -37, 32, 40, 95};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 167;

    int result = shortestSubarray(arr, n, k);

    if (result == -1) {

        printf("No valid subarray exists.\n");

    } else {

        printf("Shortest subarray length: %d\n", result);
    }

    return 0;
}
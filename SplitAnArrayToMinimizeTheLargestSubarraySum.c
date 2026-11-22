#include <stdio.h>

int requiredParts(int arr[], int n, long long limit) {

    int parts = 1;
    long long currentSum = 0;

    for (int i = 0; i < n; i++) {

        if (currentSum + arr[i] <= limit) {

            currentSum += arr[i];

        } else {

            parts++;
            currentSum = arr[i];
        }
    }

    return parts;
}

long long minimumLargestSum(int arr[], int n, int k) {

    if (k > n || k <= 0) {
        return -1;
    }

    long long left = arr[0];
    long long right = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > left) {
            left = arr[i];
        }

        right += arr[i];
    }

    long long answer = right;

    while (left <= right) {

        long long mid =
            left + (right - left) / 2;

        int parts =
            requiredParts(arr, n, mid);

        if (parts <= k) {

            answer = mid;

            // Try a smaller maximum sum
            right = mid - 1;

        } else {

            // Limit is too small
            left = mid + 1;
        }
    }

    return answer;
}

int main() {

    int arr[] = {7, 2, 5, 10, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    long long result =
        minimumLargestSum(arr, n, k);

    if (result == -1) {

        printf("Invalid value of k.\n");

    } else {

        printf("Minimum possible largest sum: %lld\n",
               result);
    }

    return 0;
}
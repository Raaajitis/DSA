#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int canSplit(int arr[], int n, int k, int maxSum) {

    int count = 1, curr = 0;

    for (int i = 0; i < n; i++) {

        if (curr + arr[i] > maxSum) {
            count++;
            curr = arr[i];

            if (count > k)
                return 0;
        } else {
            curr += arr[i];
        }
    }

    return 1;
}

int splitArray(int arr[], int n, int k) {

    int low = arr[0], high = 0;

    for (int i = 0; i < n; i++) {
        low = max(low, arr[i]);
        high += arr[i];
    }

    int result = high;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (canSplit(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {

    int arr[] = {7,2,5,10,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Min Largest Sum: %d\n",
           splitArray(arr,n,2));

    return 0;
}
#include <stdio.h>

int findPeak(int arr[], int n) {

    int left = 0, right = n - 1;

    while (left < right) {

        int mid = (left + right) / 2;

        if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {

    int arr[] = {1,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int index = findPeak(arr, n);

    printf("Peak at index: %d\n", index);

    return 0;
}
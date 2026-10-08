#include <stdio.h>

int searchRotated(int arr[], int n, int target) {

    int left = 0;
    int right = n - 1;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        // Target found
        if (arr[mid] == target) {
            return mid;
        }

        // Check if left half is sorted
        if (arr[left] <= arr[mid]) {

            // Target belongs to left half
            if (target >= arr[left] &&
                target < arr[mid]) {

                right = mid - 1;

            } else {

                left = mid + 1;
            }
        }

        // Otherwise right half is sorted
        else {

            // Target belongs to right half
            if (target > arr[mid] &&
                target <= arr[right]) {

                left = mid + 1;

            } else {

                right = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    int arr[] = {4, 5, 6, 7, 0, 1, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 0;

    int result = searchRotated(arr, n, target);

    if (result == -1) {

        printf("Element not found.\n");

    } else {

        printf("Element found at index: %d\n", result);
    }

    return 0;
}
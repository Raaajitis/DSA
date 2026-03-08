#include <stdio.h>

int binarySearch(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {

    int arr[] = {1,3,5,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int target = 7;

    int index = binarySearch(arr, n, target);

    printf("Element found at index: %d\n", index);

    return 0;
}
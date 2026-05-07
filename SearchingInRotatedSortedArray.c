#include <stdio.h>

int search(int arr[], int n, int target) {

    int left = 0, right = n - 1;

    while (left <= right) {

        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half sorted
        if (arr[left] <= arr[mid]) {

            if (target >= arr[left] &&
                target < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        // Right half sorted
        else {

            if (target > arr[mid] &&
                target <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main() {

    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Index: %d\n",
           search(arr,n,0));

    return 0;
}
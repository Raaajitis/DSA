#include <stdio.h>

long long mergeAndCount(int arr[], int temp[],
                        int left, int mid, int right) {

    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];

            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inversions;
}

long long mergeSort(int arr[], int temp[],
                    int left, int right) {

    long long inversions = 0;

    if (left < right) {

        int mid = left + (right - left) / 2;

        inversions += mergeSort(arr, temp, left, mid);

        inversions += mergeSort(arr, temp,
                                mid + 1, right);

        inversions += mergeAndCount(arr, temp,
                                    left, mid, right);
    }

    return inversions;
}

int main() {

    int arr[] = {2, 4, 1, 3, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int temp[n];

    long long result =
        mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions: %lld\n", result);

    return 0;
}
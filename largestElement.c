#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapify(int arr[], int n, int i) {

    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int kthLargest(int arr[], int n, int k) {

    // build min heap of first k elements
    for (int i = k/2 - 1; i >= 0; i--)
        heapify(arr, k, i);

    for (int i = k; i < n; i++) {

        if (arr[i] > arr[0]) {
            arr[0] = arr[i];
            heapify(arr, k, 0);
        }
    }

    return arr[0];
}

int main() {

    int arr[] = {3,2,1,5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    printf("Kth Largest: %d\n", kthLargest(arr,n,k));

    return 0;
}
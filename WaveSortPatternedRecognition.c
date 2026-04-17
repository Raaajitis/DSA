#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void waveSort(int arr[], int n) {

    for (int i = 0; i < n; i += 2) {

        if (i > 0 && arr[i] < arr[i-1])
            swap(&arr[i], &arr[i-1]);

        if (i < n-1 && arr[i] < arr[i+1])
            swap(&arr[i], &arr[i+1]);
    }
}

int main() {

    int arr[] = {3,6,5,10,7,20};
    int n = sizeof(arr)/sizeof(arr[0]);

    waveSort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
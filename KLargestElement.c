#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // descending order
}

void kLargest(int arr[], int n, int k) {

    qsort(arr, n, sizeof(int), compare);

    printf("K largest elements: ");

    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);
}

int main() {

    int arr[] = {3,2,1,5,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    kLargest(arr, n, k);

    return 0;
}
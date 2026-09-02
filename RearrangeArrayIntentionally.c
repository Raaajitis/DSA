#include <stdio.h>
#include <stdlib.h>

void rearrange(int arr[], int n) {

    int *result = (int *)malloc(n * sizeof(int));

    int left = 0;
    int right = n - 1;
    int index = 0;

    while (left <= right) {

        // Take largest
        if (index < n)
            result[index++] = arr[right--];

        // Take smallest
        if (index < n)
            result[index++] = arr[left++];
    }

    for (int i = 0; i < n; i++)
        arr[i] = result[i];

    free(result);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    rearrange(arr, n);

    printf("Rearranged Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
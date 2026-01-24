#include <stdio.h>

int main() {
    int n;
    int isSorted = 1; // Assuming that the array is sorted

    // Reading the size of array
printf("Entrer desired size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Reading array elements
    for (int i = 0; i < n; i++) {
        printf("Enter %d element of the array: " , i);
        scanf("%d", &arr[i]);
    }

    // Checking if array is sorted
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = 0;
            break;
        }
    }

    // Printing result
    if (isSorted) {
        printf("Array is sorted in ascending order");
    } else {
        printf("Array is not sorted in Ascending order");
    }

    return 0;
}
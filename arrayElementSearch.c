#include <stdio.h>

int main() {
    int n, x;

    // Reading size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Reading array elements
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reading element to search
    printf("Enter element to search: ");
    scanf("%d", &x);

    // Linear search for the element
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element found at index %d", i);
            return 0;
        }
    }

    // If elements is not found
    printf("Element not found");

    return 0;
}

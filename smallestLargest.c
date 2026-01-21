#include <stdio.h>

int main() {
    int n;

    // Reading the size of array
    printf("Size of array: ");
    scanf("%d", &n);
    
    int arr[n];

    // Reading array elements
    for (int i = 0; i < n; i++) {
        printf("Input %d number in the array: ",i);
        scanf("%d", &arr[i]);
    }

    // Initializing min and max variables
    int min = arr[0];
    int max = arr[1];

    // Traversing array to find min and max numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Printing results
    printf("Smallest: %d\n", min);
    printf("Largest: %d\n", max);

    return 0;
}

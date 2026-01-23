#include <stdio.h>

int main() {
    int n;
    int evenCount = 0, oddCount = 0;

    // Reading size of array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Reading array elements
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Counting even and odd numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    // Printing results
    printf("Number of even numbers: %d\n", evenCount);
    printf("Number of odd numbers: %d\n", oddCount);

    return 0;
}

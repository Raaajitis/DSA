#include <stdio.h>

int main() {
    int n;

    // Reading size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Reading array elements
    for (int i = 0; i < n; i++) {
        printf("Enter %d element of the array: ", i);
        scanf("%d", &arr[i]);
    }

    int temp;

    // Logic used for Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swapping if elements are in wrong order
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
printf("The sorted array is: ");
    // Printing sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

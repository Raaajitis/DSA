#include <stdio.h>

int main() {
    int n;

    // Reading size of array
    printf("Enter desired number of array elements: ");
    scanf("%d", &n);

    int arr[n];

    // Reading array elements
    for (int i = 0; i < n; i++) {
        printf ("Enter array element at %d position: " , i);
        scanf("%d", &arr[i]);
    }

    // Printing unique elements
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;

        // Checking if element appeared before
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // If not duplicate, printing element
        if (!isDuplicate) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
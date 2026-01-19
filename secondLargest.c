#include <stdio.h>

int main() {
    int n;
    
    // Reading size of array
    scanf("%d", &n);
    
    // If array size is less than 2 then second largest number cannnot exist
    if (n < 2) {
        printf("-1");
        return 0;
    }

    int arr[n];
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize largest and secondLargest variables
    int largest = arr[0];
    int secondLargest = -1;

    // Travelling through the array to find largest and second largest
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            // Updating second largest number before updating largest
            secondLargest = largest;
            largest = arr[i];
        }
        // Checking for second largest number
        else if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
    }

    // If there is no second largest element print -1
    if (secondLargest == -1) {
        printf("-1");
    } else {
        printf("%d", secondLargest);
    }

    return 0;
}

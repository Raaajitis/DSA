#include <stdio.h>

int findDuplicate(int arr[], int n) {
    int slow = arr[0];
    int fast = arr[0];

    // Phase 1: Detect cycle
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // Phase 2: Find entry point
    slow = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }

    return slow;
}

int main() {
    int arr[] = {1, 3, 4, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Duplicate Number: %d\n", findDuplicate(arr, n));

    return 0;
}
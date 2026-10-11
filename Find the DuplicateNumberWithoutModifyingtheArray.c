#include <stdio.h>

int findDuplicate(int arr[]) {

    int slow = arr[0];
    int fast = arr[0];

    // Phase 1: Find meeting point inside cycle
    do {

        slow = arr[slow];

        fast = arr[arr[fast]];

    } while (slow != fast);

    // Phase 2: Find entrance of cycle
    slow = arr[0];

    while (slow != fast) {

        slow = arr[slow];

        fast = arr[fast];
    }

    return slow;
}

int main() {

    int arr[] = {1, 3, 4, 2, 2};

    int result = findDuplicate(arr);

    printf("Duplicate number: %d\n", result);

    return 0;
}
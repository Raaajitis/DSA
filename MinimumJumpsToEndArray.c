#include <stdio.h>

int minimumJumps(int arr[], int n) {

    if (n <= 1) {
        return 0;
    }

    if (arr[0] == 0) {
        return -1;
    }

    int maxReach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++) {

        // Last index reached
        if (i == n - 1) {
            return jumps;
        }

        // Update the farthest reachable position
        if (i + arr[i] > maxReach) {
            maxReach = i + arr[i];
        }

        // One step has been used
        steps--;

        // No more steps available
        if (steps == 0) {

            jumps++;

            // Cannot move any further
            if (i >= maxReach) {
                return -1;
            }

            // New number of available steps
            steps = maxReach - i;
        }
    }

    return -1;
}

int main() {

    int arr[] = {2, 3, 1, 1, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    int result = minimumJumps(arr, n);

    if (result == -1) {
        printf("It is impossible to reach the end.\n");
    }
    else {
        printf("Minimum jumps required: %d\n", result);
    }

    return 0;
}
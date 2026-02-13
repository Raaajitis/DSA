#include <stdio.h>

int main() {

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < n; i++) {

        // Either starting new subarray or extending old one
        if (arr[i] > currentSum + arr[i])
            currentSum = arr[i];
        else
            currentSum = currentSum + arr[i];

        // Updating max sum
        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    printf("Maximum Subarray Sum = %d", maxSum);

    return 0;
}

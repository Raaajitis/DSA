#include <stdio.h>

void findLeaders(int arr[], int n) {

    int leaders[n];
    int count = 0;

    // Last element is always a leader
    int maxFromRight = arr[n - 1];

    leaders[count++] = maxFromRight;

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {

        if (arr[i] > maxFromRight) {

            leaders[count++] = arr[i];

            maxFromRight = arr[i];
        }
    }

    printf("Leaders in the array: ");

    // Leaders were found in reverse order
    for (int i = count - 1; i >= 0; i--) {

        printf("%d ", leaders[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {16, 17, 4, 3, 5, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    findLeaders(arr, n);

    return 0;
}
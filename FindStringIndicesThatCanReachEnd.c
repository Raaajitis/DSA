#include <stdio.h>

void findGoodStartingIndices(int arr[], int n) {

    int good[n];
    int count = 0;

    int leftmostGood = n - 1;

    // Last index can reach itself
    good[count++] = n - 1;

    for (int i = n - 2; i >= 0; i--) {

        if (i + arr[i] >= leftmostGood) {

            good[count++] = i;

            leftmostGood = i;
        }
    }

    printf("Indices that can reach the end: ");

    // Stored in reverse order
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", good[i]);
    }

    printf("\n");
}

int main() {

    int arr[] = {2, 3, 1, 0, 2, 0};

    int n = sizeof(arr) / sizeof(arr[0]);

    findGoodStartingIndices(arr, n);

    return 0;
}
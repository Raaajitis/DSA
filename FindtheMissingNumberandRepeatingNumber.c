#include <stdio.h>

void findMissingAndRepeating(int arr[], int n) {

    int i = 0;

    while (i < n) {

        int correctIndex = arr[i] - 1;

        if (arr[i] != arr[correctIndex]) {

            int temp = arr[i];
            arr[i] = arr[correctIndex];
            arr[correctIndex] = temp;

        } else {

            i++;
        }
    }

    int missing = -1;
    int repeating = -1;

    for (int i = 0; i < n; i++) {

        if (arr[i] != i + 1) {

            repeating = arr[i];
            missing = i + 1;

            break;
        }
    }

    printf("Repeating number: %d\n", repeating);
    printf("Missing number: %d\n", missing);
}

int main() {

    int arr[] = {4, 3, 6, 2, 1, 1};

    int n = sizeof(arr) / sizeof(arr[0]);

    findMissingAndRepeating(arr, n);

    return 0;
}
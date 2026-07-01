#include <stdio.h>

int allZero(int arr[], int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            return 0;
    return 1;
}

int main() {

    int arr[] = {4, 2, 5};
    int n = 3;
    int steps = 0;

    while (!allZero(arr, n)) {

        int next[100];

        for (int i = 0; i < n; i++) {

            int count = 0;

            for (int j = 0; j < n; j++) {

                if (arr[j] > arr[i])
                    count++;
            }

            next[i] = count;
        }

        printf("After Operation %d: ", steps + 1);

        for (int i = 0; i < n; i++) {
            arr[i] = next[i];
            printf("%d ", arr[i]);
        }

        printf("\n");

        steps++;

        if (steps > 50)
            break;
    }

    printf("\nOperations = %d\n", steps);

    return 0;
}
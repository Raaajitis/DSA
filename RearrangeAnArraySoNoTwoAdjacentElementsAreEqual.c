#include <stdio.h>

#define MAX 100

int rearrangeArray(int arr[], int n) {

    int values[MAX];
    int frequency[MAX];

    int uniqueCount = 0;

    // Count frequencies
    for (int i = 0; i < n; i++) {

        int found = -1;

        for (int j = 0; j < uniqueCount; j++) {

            if (values[j] == arr[i]) {
                found = j;
                break;
            }
        }

        if (found != -1) {

            frequency[found]++;

        } else {

            values[uniqueCount] = arr[i];
            frequency[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    int result[MAX];
    int previous = -1;

    for (int position = 0;
         position < n;
         position++) {

        int best = -1;

        /*
         * Find the most frequent value
         * different from the previous one.
         */
        for (int i = 0; i < uniqueCount; i++) {

            if (frequency[i] > 0 &&
                i != previous) {

                if (best == -1 ||
                    frequency[i] > frequency[best]) {

                    best = i;
                }
            }
        }

        // No valid element can be placed
        if (best == -1) {
            return 0;
        }

        result[position] = values[best];

        frequency[best]--;

        previous = best;
    }

    printf("Rearranged array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    return 1;
}

int main() {

    int arr[] = {1, 1, 1, 2, 2, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    if (!rearrangeArray(arr, n)) {

        printf("Rearrangement is impossible.\n");
    }

    return 0;
}
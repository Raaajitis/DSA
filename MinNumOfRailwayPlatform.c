#include <stdio.h>

void sortArray(int arr[], int n) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int minimumPlatforms(int arrival[], int departure[], int n) {

    sortArray(arrival, n);
    sortArray(departure, n);

    int platforms = 1;
    int maxPlatforms = 1;

    int i = 1;
    int j = 0;

    while (i < n && j < n) {

        if (arrival[i] <= departure[j]) {

            platforms++;
            i++;

            if (platforms > maxPlatforms) {
                maxPlatforms = platforms;
            }
        }
        else {

            platforms--;
            j++;
        }
    }

    return maxPlatforms;
}

int main() {

    int arrival[] = {
        900, 940, 950, 1100, 1500, 1800
    };

    int departure[] = {
        910, 1200, 1120, 1130, 1900, 2000
    };

    int n = sizeof(arrival) / sizeof(arrival[0]);

    int result = minimumPlatforms(arrival, departure, n);

    printf("Minimum platforms required: %d\n", result);

    return 0;
}
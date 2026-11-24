#include <stdio.h>

int findStartingStation(int gain[],
                        int cost[],
                        int n) {

    int total = 0;
    int current = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {

        int difference =
            gain[i] - cost[i];

        total += difference;
        current += difference;

        if (current < 0) {

            start = i + 1;
            current = 0;
        }
    }

    // Total resources are insufficient
    if (total < 0) {
        return -1;
    }

    return start;
}

int main() {

    int gain[] = {1, 2, 5, 3, 4};
    int cost[] = {3, 2, 2, 4, 2};

    int n = sizeof(gain) / sizeof(gain[0]);

    int result =
        findStartingStation(gain, cost, n);

    if (result == -1) {

        printf("Circular route is impossible.\n");

    } else {

        printf("Start from station index: %d\n",
               result);
    }

    return 0;
}
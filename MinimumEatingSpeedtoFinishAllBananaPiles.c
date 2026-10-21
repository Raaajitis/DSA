#include <stdio.h>

long long hoursRequired(int piles[], int n, int speed) {

    long long hours = 0;

    for (int i = 0; i < n; i++) {

        hours +=
            ((long long)piles[i] + speed - 1) / speed;
    }

    return hours;
}

int minimumSpeed(int piles[], int n, int h) {

    int maxPile = piles[0];

    for (int i = 1; i < n; i++) {

        if (piles[i] > maxPile) {
            maxPile = piles[i];
        }
    }

    int left = 1;
    int right = maxPile;

    int answer = maxPile;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        long long hours =
            hoursRequired(piles, n, mid);

        if (hours <= h) {

            answer = mid;

            // Try a smaller speed
            right = mid - 1;
        }
        else {

            // Speed is too slow
            left = mid + 1;
        }
    }

    return answer;
}

int main() {

    int piles[] = {3, 6, 7, 11};

    int n = sizeof(piles) / sizeof(piles[0]);

    int h = 8;

    int result = minimumSpeed(piles, n, h);

    printf("Minimum eating speed: %d\n", result);

    return 0;
}
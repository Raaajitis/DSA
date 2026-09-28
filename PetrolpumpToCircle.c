#include <stdio.h>

int findStartingPump(int petrol[], int distance[], int n) {

    int totalPetrol = 0;
    int currentPetrol = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {

        int difference = petrol[i] - distance[i];

        totalPetrol += difference;
        currentPetrol += difference;

        // Current starting point has failed
        if (currentPetrol < 0) {

            // Try starting from the next pump
            start = i + 1;

            currentPetrol = 0;
        }
    }

    // Not enough petrol exists to complete the journey
    if (totalPetrol < 0) {
        return -1;
    }

    return start;
}

int main() {

    int petrol[] = {4, 6, 7, 4};

    int distance[] = {6, 5, 3, 5};

    int n = sizeof(petrol) / sizeof(petrol[0]);

    int result = findStartingPump(petrol, distance, n);

    if (result == -1) {

        printf("Circular tour is not possible.\n");

    } else {

        printf("Start from petrol pump %d.\n", result);
    }

    return 0;
}
#include <stdio.h>

#define MAX 100

struct Station {
    int position;
    int fuel;
};

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertMaxHeap(int heap[], int *size, int value) {

    int index = *size;

    heap[index] = value;

    (*size)++;

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (heap[parent] >= heap[index]) {
            break;
        }

        swap(&heap[parent], &heap[index]);

        index = parent;
    }
}

int extractMax(int heap[], int *size) {

    if (*size == 0) {
        return -1;
    }

    int maximum = heap[0];

    heap[0] = heap[*size - 1];

    (*size)--;

    int index = 0;

    while (1) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int largest = index;

        if (left < *size &&
            heap[left] > heap[largest]) {

            largest = left;
        }

        if (right < *size &&
            heap[right] > heap[largest]) {

            largest = right;
        }

        if (largest == index) {
            break;
        }

        swap(&heap[index], &heap[largest]);

        index = largest;
    }

    return maximum;
}

int minimumRefuelStops(
    int target,
    int startFuel,
    struct Station stations[],
    int n) {

    int heap[MAX];
    int heapSize = 0;

    long long reachable = startFuel;

    int stationIndex = 0;
    int stops = 0;

    while (reachable < target) {

        // Add every reachable station
        while (stationIndex < n &&
               stations[stationIndex].position <= reachable) {

            insertMaxHeap(
                heap,
                &heapSize,
                stations[stationIndex].fuel
            );

            stationIndex++;
        }

        // No reachable station can provide fuel
        if (heapSize == 0) {
            return -1;
        }

        // Take the largest available fuel
        int fuel = extractMax(heap, &heapSize);

        reachable += fuel;

        stops++;
    }

    return stops;
}

int main() {

    int target = 100;
    int startFuel = 10;

    struct Station stations[] = {
        {10, 60},
        {20, 30},
        {30, 30},
        {60, 40}
    };

    int n =
        sizeof(stations) / sizeof(stations[0]);

    int result =
        minimumRefuelStops(
            target,
            startFuel,
            stations,
            n
        );

    if (result == -1) {

        printf("Destination cannot be reached.\n");

    } else {

        printf("Minimum refueling stops: %d\n",
               result);
    }

    return 0;
}
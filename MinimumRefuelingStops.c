#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long position;
    long long fuel;
} Station;

int compareStations(const void *first, const void *second) {
    const Station *a = first;
    const Station *b = second;

    if (a->position < b->position) return -1;
    if (a->position > b->position) return 1;
    return 0;
}

void heapPush(long long *heap, int *size, long long value) {
    int index = (*size)++;
    heap[index] = value;

    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] >= heap[index]) {
            break;
        }

        long long temporary = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temporary;

        index = parent;
    }
}

long long heapPopMaximum(long long *heap, int *size) {
    long long result = heap[0];

    (*size)--;
    heap[0] = heap[*size];

    int index = 0;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < *size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < *size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest == index) {
            break;
        }

        long long temporary = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temporary;

        index = largest;
    }

    return result;
}

int main(void) {
    int n;
    long long destination;
    long long initialFuel;

    scanf("%d %lld %lld", &n, &destination, &initialFuel);

    Station *stations = malloc(n * sizeof(Station));
    long long *maximumHeap = malloc((n + 1) * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf(
            "%lld %lld",
            &stations[i].position,
            &stations[i].fuel
        );
    }

    qsort(stations, n, sizeof(Station), compareStations);

    long long reachableDistance = initialFuel;
    int stationIndex = 0;
    int heapSize = 0;
    int stops = 0;

    while (reachableDistance < destination) {
        while (stationIndex < n &&
               stations[stationIndex].position <= reachableDistance) {
            heapPush(
                maximumHeap,
                &heapSize,
                stations[stationIndex].fuel
            );

            stationIndex++;
        }

        if (heapSize == 0) {
            printf("-1\n");

            free(stations);
            free(maximumHeap);
            return 0;
        }

        reachableDistance += heapPopMaximum(
            maximumHeap,
            &heapSize
        );

        stops++;
    }

    printf("%d\n", stops);

    free(stations);
    free(maximumHeap);

    return 0;
}
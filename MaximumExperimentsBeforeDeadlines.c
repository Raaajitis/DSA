#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long duration;
    long long deadline;
} Experiment;

int compareExperiments(const void *first, const void *second) {
    const Experiment *a = first;
    const Experiment *b = second;

    if (a->deadline < b->deadline) return -1;
    if (a->deadline > b->deadline) return 1;

    if (a->duration < b->duration) return -1;
    if (a->duration > b->duration) return 1;

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
    long long maximum = heap[0];

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

    return maximum;
}

int main(void) {
    int n;
    scanf("%d", &n);

    Experiment *experiments =
        malloc(n * sizeof(Experiment));

    for (int i = 0; i < n; i++) {
        scanf(
            "%lld %lld",
            &experiments[i].duration,
            &experiments[i].deadline
        );
    }

    qsort(
        experiments,
        n,
        sizeof(Experiment),
        compareExperiments
    );

    long long *maximumHeap =
        malloc(n * sizeof(long long));

    int heapSize = 0;
    long long totalTime = 0;

    for (int i = 0; i < n; i++) {
        totalTime += experiments[i].duration;

        heapPush(
            maximumHeap,
            &heapSize,
            experiments[i].duration
        );

        if (totalTime > experiments[i].deadline) {
            totalTime -= heapPopMaximum(
                maximumHeap,
                &heapSize
            );
        }
    }

    printf("%d\n", heapSize);

    free(experiments);
    free(maximumHeap);

    return 0;
}
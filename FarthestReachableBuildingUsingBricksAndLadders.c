#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertMinHeap(int heap[], int *size, int value) {

    int index = *size;

    heap[index] = value;
    (*size)++;

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index]) {
            break;
        }

        swap(&heap[parent], &heap[index]);

        index = parent;
    }
}

int extractMin(int heap[], int *size) {

    int minimum = heap[0];

    heap[0] = heap[*size - 1];
    (*size)--;

    int index = 0;

    while (1) {

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int smallest = index;

        if (left < *size &&
            heap[left] < heap[smallest]) {

            smallest = left;
        }

        if (right < *size &&
            heap[right] < heap[smallest]) {

            smallest = right;
        }

        if (smallest == index) {
            break;
        }

        swap(&heap[index], &heap[smallest]);

        index = smallest;
    }

    return minimum;
}

int farthestBuilding(int heights[],
                     int n,
                     int bricks,
                     int ladders) {

    int heap[MAX];
    int heapSize = 0;

    for (int i = 0; i < n - 1; i++) {

        int climb =
            heights[i + 1] - heights[i];

        // No resource required
        if (climb <= 0) {
            continue;
        }

        insertMinHeap(
            heap,
            &heapSize,
            climb
        );

        /*
         * More climbs than ladders:
         * use bricks for the smallest climb.
         */
        if (heapSize > ladders) {

            int smallestClimb =
                extractMin(heap, &heapSize);

            bricks -= smallestClimb;
        }

        if (bricks < 0) {
            return i;
        }
    }

    return n - 1;
}

int main() {

    int heights[] = {
        4, 2, 7, 6, 9, 14, 12
    };

    int n =
        sizeof(heights) / sizeof(heights[0]);

    int bricks = 5;
    int ladders = 1;

    int result =
        farthestBuilding(
            heights,
            n,
            bricks,
            ladders
        );

    printf("Farthest reachable building index: %d\n",
           result);

    return 0;
}
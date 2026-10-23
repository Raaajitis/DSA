#include <stdio.h>

#define MAX 100

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {

    while (index > 0) {

        int parent = (index - 1) / 2;

        if (heap[parent] <= heap[index]) {
            break;
        }

        swap(&heap[parent], &heap[index]);

        index = parent;
    }
}

void heapifyDown(int heap[], int size, int index) {

    while (1) {

        int smallest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size &&
            heap[left] < heap[smallest]) {

            smallest = left;
        }

        if (right < size &&
            heap[right] < heap[smallest]) {

            smallest = right;
        }

        if (smallest == index) {
            break;
        }

        swap(&heap[index], &heap[smallest]);

        index = smallest;
    }
}

void insertHeap(int heap[], int *size, int value) {

    heap[*size] = value;

    (*size)++;

    heapifyUp(heap, *size - 1);
}

int extractMin(int heap[], int *size) {

    int minimum = heap[0];

    heap[0] = heap[*size - 1];

    (*size)--;

    if (*size > 0) {
        heapifyDown(heap, *size, 0);
    }

    return minimum;
}

int minimumRopeCost(int ropes[], int n) {

    if (n <= 1) {
        return 0;
    }

    int heap[MAX];
    int size = 0;

    for (int i = 0; i < n; i++) {

        insertHeap(heap, &size, ropes[i]);
    }

    int totalCost = 0;

    while (size > 1) {

        int first = extractMin(heap, &size);

        int second = extractMin(heap, &size);

        int combined = first + second;

        totalCost += combined;

        insertHeap(heap, &size, combined);
    }

    return totalCost;
}

int main() {

    int ropes[] = {4, 3, 2, 6};

    int n = sizeof(ropes) / sizeof(ropes[0]);

    int result = minimumRopeCost(ropes, n);

    printf("Minimum cost to connect ropes: %d\n",
           result);

    return 0;
}
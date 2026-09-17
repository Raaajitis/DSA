#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int destination;
    long long weight;
    int next;
} Edge;

typedef struct {
    int state;
    long long distance;
} HeapNode;

typedef struct {
    HeapNode *data;
    int size;
    int capacity;
} MinHeap;

void heapPush(
    MinHeap *heap,
    int state,
    long long distance
) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = realloc(
            heap->data,
            heap->capacity * sizeof(HeapNode)
        );
    }

    int index = heap->size++;
    heap->data[index] = (HeapNode){state, distance};

    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap->data[parent].distance <=
            heap->data[index].distance) {
            break;
        }

        HeapNode temporary = heap->data[parent];
        heap->data[parent] = heap->data[index];
        heap->data[index] = temporary;

        index = parent;
    }
}

HeapNode heapPop(MinHeap *heap) {
    HeapNode result = heap->data[0];

    heap->size--;
    heap->data[0] = heap->data[heap->size];

    int index = 0;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap->size &&
            heap->data[left].distance <
            heap->data[smallest].distance) {
            smallest = left;
        }

        if (right < heap->size &&
            heap->data[right].distance <
            heap->data[smallest].distance) {
            smallest = right;
        }

        if (smallest == index) {
            break;
        }

        HeapNode temporary = heap->data[index];
        heap->data[index] = heap->data[smallest];
        heap->data[smallest] = temporary;

        index = smallest;
    }

    return result;
}

void relax(
    long long *distance,
    MinHeap *heap,
    int state,
    long long candidate
) {
    if (candidate < distance[state]) {
        distance[state] = candidate;
        heapPush(heap, state, candidate);
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int *head = malloc((n + 1) * sizeof(int));
    Edge *edges = malloc(m * sizeof(Edge));

    for (int city = 1; city <= n; city++) {
        head[city] = -1;
    }

    for (int i = 0; i < m; i++) {
        int from, to;
        long long weight;

        scanf("%d %d %lld", &from, &to, &weight);

        edges[i].destination = to;
        edges[i].weight = weight;
        edges[i].next = head[from];
        head[from] = i;
    }

    int stateCount = 2 * (n + 1);
    long long *distance =
        malloc(stateCount * sizeof(long long));

    const long long INFINITY = LLONG_MAX / 4;

    for (int i = 0; i < stateCount; i++) {
        distance[i] = INFINITY;
    }

    MinHeap heap;
    heap.size = 0;
    heap.capacity = 16;
    heap.data = malloc(
        heap.capacity * sizeof(HeapNode)
    );

    /* State encoding: city * 2 + couponUsed */
    int startingState = 1 * 2;
    distance[startingState] = 0;
    heapPush(&heap, startingState, 0);

    while (heap.size > 0) {
        HeapNode current = heapPop(&heap);

        if (current.distance != distance[current.state]) {
            continue;
        }

        int city = current.state / 2;
        int couponUsed = current.state % 2;

        for (int edgeIndex = head[city];
             edgeIndex != -1;
             edgeIndex = edges[edgeIndex].next) {

            Edge edge = edges[edgeIndex];

            int normalState =
                edge.destination * 2 + couponUsed;

            relax(
                distance,
                &heap,
                normalState,
                current.distance + edge.weight
            );

            if (!couponUsed) {
                int discountedState =
                    edge.destination * 2 + 1;

                relax(
                    distance,
                    &heap,
                    discountedState,
                    current.distance + edge.weight / 2
                );
            }
        }
    }

    long long answer = distance[n * 2];

    if (distance[n * 2 + 1] < answer) {
        answer = distance[n * 2 + 1];
    }

    if (answer == INFINITY) {
        printf("-1\n");
    } else {
        printf("%lld\n", answer);
    }

    free(head);
    free(edges);
    free(distance);
    free(heap.data);

    return 0;
}
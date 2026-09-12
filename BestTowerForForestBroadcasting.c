#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    int distance;
} BFSResult;

void addEdge(
    int from,
    int to,
    int *head,
    int *destination,
    int *next,
    int edgeIndex
) {
    destination[edgeIndex] = to;
    next[edgeIndex] = head[from];
    head[from] = edgeIndex;
}

BFSResult findFarthest(
    int start,
    int n,
    const int *head,
    const int *destination,
    const int *next
) {
    int *queue = malloc(n * sizeof(int));
    int *distance = malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++) {
        distance[i] = -1;
    }

    int front = 0;
    int back = 0;

    queue[back++] = start;
    distance[start] = 0;

    BFSResult result;
    result.node = start;
    result.distance = 0;

    while (front < back) {
        int current = queue[front++];

        if (distance[current] > result.distance) {
            result.node = current;
            result.distance = distance[current];
        }

        for (int edge = head[current];
             edge != -1;
             edge = next[edge]) {

            int neighbour = destination[edge];

            if (distance[neighbour] == -1) {
                distance[neighbour] = distance[current] + 1;
                queue[back++] = neighbour;
            }
        }
    }

    free(queue);
    free(distance);

    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);

    if (n == 1) {
        printf("0\n");
        return 0;
    }

    int edgeCount = 2 * (n - 1);

    int *head = malloc((n + 1) * sizeof(int));
    int *destination = malloc(edgeCount * sizeof(int));
    int *next = malloc(edgeCount * sizeof(int));

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }

    int edgeIndex = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(u, v, head, destination, next, edgeIndex++);
        addEdge(v, u, head, destination, next, edgeIndex++);
    }

    BFSResult first = findFarthest(
        1, n, head, destination, next
    );

    BFSResult second = findFarthest(
        first.node, n, head, destination, next
    );

    int diameter = second.distance;
    int minimumSeconds = (diameter + 1) / 2;

    printf("%d\n", minimumSeconds);

    free(head);
    free(destination);
    free(next);

    return 0;
}
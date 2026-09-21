#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void pushFront(
    int *deque,
    int capacity,
    int *front,
    int value
) {
    *front = (*front - 1 + capacity) % capacity;
    deque[*front] = value;
}

void pushBack(
    int *deque,
    int capacity,
    int *back,
    int value
) {
    deque[*back] = value;
    *back = (*back + 1) % capacity;
}

int popFront(
    const int *deque,
    int capacity,
    int *front
) {
    int value = deque[*front];
    *front = (*front + 1) % capacity;
    return value;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    char **grid = malloc(n * sizeof(char *));

    for (int row = 0; row < n; row++) {
        grid[row] = malloc((m + 1) * sizeof(char));
        scanf("%s", grid[row]);
    }

    int totalCells = n * m;
    int *distance = malloc(totalCells * sizeof(int));

    for (int i = 0; i < totalCells; i++) {
        distance[i] = INT_MAX;
    }

    /*
     * A successful relaxation can occur at most once per grid edge,
     * so this capacity is sufficient for all queued entries.
     */
    int dequeCapacity = 4 * totalCells + 5;
    int *deque = malloc(dequeCapacity * sizeof(int));

    int front = 0;
    int back = 0;
    int dequeSize = 0;

    distance[0] = 0;
    pushBack(deque, dequeCapacity, &back, 0);
    dequeSize++;

    int rowChange[] = {-1, 1, 0, 0};
    int columnChange[] = {0, 0, -1, 1};
    char direction[] = {'U', 'D', 'L', 'R'};

    while (dequeSize > 0) {
        int current = popFront(
            deque,
            dequeCapacity,
            &front
        );
        dequeSize--;

        int row = current / m;
        int column = current % m;

        for (int d = 0; d < 4; d++) {
            int newRow = row + rowChange[d];
            int newColumn = column + columnChange[d];

            if (newRow < 0 || newRow >= n ||
                newColumn < 0 || newColumn >= m) {
                continue;
            }

            int next = newRow * m + newColumn;
            int movementCost =
                grid[row][column] == direction[d] ? 0 : 1;

            int newDistance =
                distance[current] + movementCost;

            if (newDistance < distance[next]) {
                distance[next] = newDistance;

                if (movementCost == 0) {
                    pushFront(
                        deque,
                        dequeCapacity,
                        &front,
                        next
                    );
                } else {
                    pushBack(
                        deque,
                        dequeCapacity,
                        &back,
                        next
                    );
                }

                dequeSize++;
            }
        }
    }

    printf("%d\n", distance[totalCells - 1]);

    for (int row = 0; row < n; row++) {
        free(grid[row]);
    }

    free(grid);
    free(distance);
    free(deque);

    return 0;
}
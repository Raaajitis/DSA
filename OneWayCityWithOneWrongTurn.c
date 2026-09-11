#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int node;
    int usedReverse;
} State;

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

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int *outHead = malloc((n + 1) * sizeof(int));
    int *inHead = malloc((n + 1) * sizeof(int));

    int *outDestination = malloc(m * sizeof(int));
    int *outNext = malloc(m * sizeof(int));

    int *inDestination = malloc(m * sizeof(int));
    int *inNext = malloc(m * sizeof(int));

    for (int i = 1; i <= n; i++) {
        outHead[i] = -1;
        inHead[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        /* Original outgoing edge: u -> v */
        addEdge(
            u, v, outHead,
            outDestination, outNext, i
        );

        /*
         * Store u in v's incoming list.
         * This lets us travel from v to u in reverse.
         */
        addEdge(
            v, u, inHead,
            inDestination, inNext, i
        );
    }

    int totalStates = 2 * (n + 1);
    int *distance = malloc(totalStates * sizeof(int));
    State *queue = malloc(2 * n * sizeof(State));

    for (int i = 0; i < totalStates; i++) {
        distance[i] = -1;
    }

    int front = 0;
    int back = 0;

    queue[back++] = (State){1, 0};
    distance[1 * 2] = 0;

    while (front < back) {
        State current = queue[front++];
        int currentIndex = current.node * 2 + current.usedReverse;
        int currentDistance = distance[currentIndex];

        /* Travel through roads in their normal direction. */
        for (int edge = outHead[current.node];
             edge != -1;
             edge = outNext[edge]) {

            int nextNode = outDestination[edge];
            int nextIndex = nextNode * 2 + current.usedReverse;

            if (distance[nextIndex] == -1) {
                distance[nextIndex] = currentDistance + 1;
                queue[back++] = (State){
                    nextNode,
                    current.usedReverse
                };
            }
        }

        /* Use one road in its reverse direction. */
        if (current.usedReverse == 0) {
            for (int edge = inHead[current.node];
                 edge != -1;
                 edge = inNext[edge]) {

                int nextNode = inDestination[edge];
                int nextIndex = nextNode * 2 + 1;

                if (distance[nextIndex] == -1) {
                    distance[nextIndex] = currentDistance + 1;
                    queue[back++] = (State){nextNode, 1};
                }
            }
        }
    }

    int withoutReverse = distance[n * 2];
    int withReverse = distance[n * 2 + 1];
    int answer;

    if (withoutReverse == -1) {
        answer = withReverse;
    } else if (withReverse == -1) {
        answer = withoutReverse;
    } else {
        answer = withoutReverse < withReverse
                   ? withoutReverse
                   : withReverse;
    }

    printf("%d\n", answer);

    free(outHead);
    free(inHead);
    free(outDestination);
    free(outNext);
    free(inDestination);
    free(inNext);
    free(distance);
    free(queue);

    return 0;
}
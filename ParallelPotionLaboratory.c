#include <stdio.h>
#include <stdlib.h>

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

    long long *time = malloc((n + 1) * sizeof(long long));
    long long *finish = malloc((n + 1) * sizeof(long long));

    int *indegree = calloc(n + 1, sizeof(int));
    int *head = malloc((n + 1) * sizeof(int));
    int *destination = malloc(m * sizeof(int));
    int *next = malloc(m * sizeof(int));
    int *queue = malloc(n * sizeof(int));

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &time[i]);
        finish[i] = time[i];
        head[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(u, v, head, destination, next, i);
        indegree[v]++;
    }

    int front = 0;
    int back = 0;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            queue[back++] = i;
        }
    }

    int processed = 0;
    long long answer = 0;

    while (front < back) {
        int current = queue[front++];
        processed++;

        if (finish[current] > answer) {
            answer = finish[current];
        }

        for (int edge = head[current];
             edge != -1;
             edge = next[edge]) {

            int nextPotion = destination[edge];

            long long candidate =
                finish[current] + time[nextPotion];

            if (candidate > finish[nextPotion]) {
                finish[nextPotion] = candidate;
            }

            indegree[nextPotion]--;

            if (indegree[nextPotion] == 0) {
                queue[back++] = nextPotion;
            }
        }
    }

    if (processed != n) {
        printf("-1\n");
    } else {
        printf("%lld\n", answer);
    }

    free(time);
    free(finish);
    free(indegree);
    free(head);
    free(destination);
    free(next);
    free(queue);

    return 0;
}
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];

int hasCycle(int V) {

    int indegree[MAX] = {0};

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adj[i][j])
                indegree[j]++;

    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int count = 0;

    while (front < rear) {

        int node = queue[front++];
        count++;

        for (int i = 0; i < V; i++) {

            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    return count != V;
}

int main() {

    int V = 3;

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1; // cycle

    if (hasCycle(V))
        printf("Cycle Exists\n");
    else
        printf("No Cycle\n");

    return 0;
}
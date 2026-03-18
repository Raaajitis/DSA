#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];

void topologicalSort(int V) {

    int queue[MAX];
    int front = 0, rear = -1;

    // Add nodes with 0 indegree
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[++rear] = i;

    while (front <= rear) {

        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < V; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[++rear] = i;
            }
        }
    }
}

int main() {

    int V = 4;

    // adjacency matrix
    adj[0][1] = 1;
    adj[0][2] = 1;
    adj[1][3] = 1;
    adj[2][3] = 1;

    indegree[1] = 1;
    indegree[2] = 1;
    indegree[3] = 2;

    printf("Topological Order: ");
    topologicalSort(V);

    return 0;
}
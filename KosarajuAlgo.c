#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], rev[MAX][MAX];
int visited[MAX], stack[MAX], top = -1;

void dfs1(int v, int V) {

    visited[v] = 1;

    for (int i = 0; i < V; i++)
        if (adj[v][i] && !visited[i])
            dfs1(i, V);

    stack[++top] = v;
}

void dfs2(int v, int V) {

    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < V; i++)
        if (rev[v][i] && !visited[i])
            dfs2(i, V);
}

void kosaraju(int V) {

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i, V);

    // reverse graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (adj[i][j])
                rev[j][i] = 1;

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    printf("SCCs:\n");

    while (top >= 0) {

        int v = stack[top--];

        if (!visited[v]) {
            dfs2(v, V);
            printf("\n");
        }
    }
}

int main() {

    int V = 5;

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;
    adj[1][3] = 1;
    adj[3][4] = 1;

    kosaraju(V);

    return 0;
}
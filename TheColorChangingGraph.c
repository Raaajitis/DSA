#include <stdio.h>

#define N 4

int graph[N][N] = {
    {0,1,1,0},
    {1,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
};

int color[N] = {0,0,0,0};
int visited[N] = {0};

void dfs(int node) {

    visited[node] = 1;

    for(int i = 0; i < N; i++) {

        if(graph[node][i])
            color[i] ^= 1;
    }

    for(int i = 0; i < N; i++) {

        if(graph[node][i] &&
           !visited[i]) {

            dfs(i);
        }
    }
}

int main() {

    dfs(0);

    printf("Final Colors:\n");

    for(int i = 0; i < N; i++)
        printf("%d ", color[i]);

    return 0;
}
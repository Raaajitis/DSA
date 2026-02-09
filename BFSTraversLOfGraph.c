#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = 0, rear = 0;

int visited[MAX];

// Enqueue function
void enqueue(int value) {
    queue[rear++] = value;
}

// Dequeue function
int dequeue() {
    return queue[front++];
}

// BFS Traversal
void bfs(int graph[MAX][MAX], int start, int n) {

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {

        int current = dequeue();
        printf("%d ", current);

        // Visit all adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {

    int n = 5;

    // Adjacency Matrix of Graph
    int graph[MAX][MAX] = {
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,0,0},
        {1,0,0,0,1},
        {0,1,0,1,0}
    };

    bfs(graph, 0, n);

    return 0;
}

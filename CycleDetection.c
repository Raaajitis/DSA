#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// DFS to detect cycle
bool dfs(struct Graph* graph, int v, bool visited[], bool recStack[]) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        struct Node* temp = graph->adj[v];
        while (temp != NULL) {
            int neighbor = temp->vertex;

            if (!visited[neighbor] && dfs(graph, neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;

            temp = temp->next;
        }
    }

    recStack[v] = false;
    return false;
}

// Check cycle
bool isCyclic(struct Graph* graph) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};

    for (int i = 0; i < graph->V; i++)
        if (dfs(graph, i, visited, recStack))
            return true;

    return false;
}

int main() {
    struct Graph* graph = createGraph(4);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);  // Cycle here

    if (isCyclic(graph))
        printf("Cycle exists\n");
    else
        printf("No cycle\n");

    return 0;
}
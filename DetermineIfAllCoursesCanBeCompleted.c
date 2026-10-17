#include <stdio.h>

#define MAX 100

int canFinish(int n, int graph[MAX][MAX]) {

    int indegree[MAX] = {0};
    int queue[MAX];

    int front = 0;
    int rear = 0;

    // Calculate indegree
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Add courses with no prerequisites
    for (int i = 0; i < n; i++) {

        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int completed = 0;

    while (front < rear) {

        int course = queue[front++];

        completed++;

        // Remove this course from graph
        for (int next = 0; next < n; next++) {

            if (graph[course][next] == 1) {

                indegree[next]--;

                if (indegree[next] == 0) {
                    queue[rear++] = next;
                }
            }
        }
    }

    return completed == n;
}

int main() {

    int n = 4;

    int graph[MAX][MAX] = {0};

    /*
       Prerequisites:

       [1, 0]
       [2, 1]
       [3, 2]

       Therefore:

       0 -> 1
       1 -> 2
       2 -> 3
    */

    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;

    if (canFinish(n, graph)) {

        printf("All courses can be completed.\n");

    } else {

        printf("All courses cannot be completed.\n");
    }

    return 0;
}
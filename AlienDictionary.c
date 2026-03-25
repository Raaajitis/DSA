#include <stdio.h>

#define MAX 26

int adj[MAX][MAX];
int visited[MAX];

void dfs(int v, int stack[], int *top) {
    visited[v] = 1;

    for (int i = 0; i < MAX; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i, stack, top);
    }

    stack[++(*top)] = v;
}

void alienOrder(char *words[], int n) {

    // Build graph
    for (int i = 0; i < n - 1; i++) {
        char *w1 = words[i];
        char *w2 = words[i + 1];

        for (int j = 0; w1[j] && w2[j]; j++) {
            if (w1[j] != w2[j]) {
                adj[w1[j]-'a'][w2[j]-'a'] = 1;
                break;
            }
        }
    }

    int stack[MAX], top = -1;

    for (int i = 0; i < MAX; i++) {
        if (!visited[i]) {
            dfs(i, stack, &top);
        }
    }

    printf("Character Order: ");
    while (top >= 0)
        printf("%c ", stack[top--] + 'a');
}

int main() {

    char *words[] = {"baa","abcd","abca","cab","cad"};
    int n = 5;

    alienOrder(words, n);

    return 0;
}
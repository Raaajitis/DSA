#include <stdio.h>
#include <string.h>

#define MAX 26

int adj[MAX][MAX];
int visited[MAX];
char result[MAX];
int index = 0;

void dfs(int v) {

    visited[v] = 1;

    for (int i = 0; i < MAX; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i);
    }

    result[index++] = v + 'a';
}

void alien(char words[][10], int n) {

    for (int i = 0; i < n - 1; i++) {

        char *w1 = words[i];
        char *w2 = words[i+1];

        for (int j = 0; w1[j] && w2[j]; j++) {
            if (w1[j] != w2[j]) {
                adj[w1[j]-'a'][w2[j]-'a'] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < MAX; i++)
        if (!visited[i])
            dfs(i);

    for (int i = index - 1; i >= 0; i--)
        printf("%c ", result[i]);
}

int main() {

    char words[][10] = {"baa","abcd","abca","cab","cad"};
    int n = 5;

    alien(words, n);

    return 0;
}
#include <stdio.h>

#define MAX 100

int parent[MAX];
int rank[MAX];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]); // path compression
    return parent[x];
}

void unionSet(int a, int b) {

    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {

        if (rank[rootA] < rank[rootB])
            parent[rootA] = rootB;

        else if (rank[rootA] > rank[rootB])
            parent[rootB] = rootA;

        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }
    }
}

int main() {

    makeSet(5);

    unionSet(0,1);
    unionSet(1,2);
    unionSet(3,4);

    printf("Find(2): %d\n", find(2));
    printf("Find(4): %d\n", find(4));

    return 0;
}
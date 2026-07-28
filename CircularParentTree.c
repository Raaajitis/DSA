#include <stdio.h>

#define MAXN 100005

int parent[MAXN];
int depth[MAXN];

int main() {

    int n, q;

    scanf("%d%d", &n, &q);

    parent[1] = 0;
    depth[1] = 0;

    for(int i = 2; i <= n; i++) {
        scanf("%d", &parent[i]);
        depth[i] = depth[parent[i]] + 1;
    }

    while(q--) {

        int u, k;
        scanf("%d%d", &u, &k);

        int original = u;
        int deepest = original;

        while(parent[deepest] != 1)
            deepest = parent[deepest];

        while(k--) {

            if(u == 1)
                u = original;
            else
                u = parent[u];
        }

        printf("%d\n", u);
    }

    return 0;
}
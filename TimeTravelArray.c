#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MAXNODE 4000005

typedef struct {
    int left;
    int right;
    int value;
} Node;

Node tree[MAXNODE];

int root[MAXN];
int nodes = 0;
int n, q;

int build(int l, int r, int a[]) {
    int cur = ++nodes;

    if (l == r) {
        tree[cur].value = a[l];
        return cur;
    }

    int mid = (l + r) / 2;

    tree[cur].left = build(l, mid, a);
    tree[cur].right = build(mid + 1, r, a);

    return cur;
}

int update(int oldNode, int l, int r, int pos, int value) {
    int cur = ++nodes;

    tree[cur] = tree[oldNode];

    if (l == r) {
        tree[cur].value = value;
        return cur;
    }

    int mid = (l + r) / 2;

    if (pos <= mid) {
        tree[cur].left =
            update(tree[oldNode].left, l, mid, pos, value);
    } else {
        tree[cur].right =
            update(tree[oldNode].right, mid + 1, r, pos, value);
    }

    return cur;
}

int query(int node, int l, int r, int pos) {
    if (l == r)
        return tree[node].value;

    int mid = (l + r) / 2;

    if (pos <= mid)
        return query(tree[node].left, l, mid, pos);

    return query(tree[node].right, mid + 1, r, pos);
}

int main() {

    scanf("%d%d", &n, &q);

    int *a = malloc((n + 1) * sizeof(int));

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    /*
     * root[0] = initial state
     */
    root[0] = build(1, n, a);

    int versions = 0;

    while (q--) {

        int type;
        scanf("%d", &type);

        if (type == 1) {

            int i, x;

            scanf("%d%d", &i, &x);

            /*
             * Create a new version from
             * the current version.
             */
            root[versions + 1] =
                update(root[versions], 1, n, i, x);

            versions++;

        } else if (type == 2) {

            int k;

            scanf("%d", &k);

            /*
             * Current version = versions
             *
             * k updates into the past:
             *
             * version = versions - k
             */
            int historicalVersion = versions - k;

            if (historicalVersion < 0)
                historicalVersion = 0;

            /*
             * Query the first element A[1]
             * of that historical version.
             */
            printf("%d\n",
                   query(root[historicalVersion],
                         1, n, 1));
        }
    }

    free(a);

    return 0;
}
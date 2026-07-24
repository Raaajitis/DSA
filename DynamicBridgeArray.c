#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int A[MAXN];
int bridge[MAXN];
int seg[4 * MAXN];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void computeBridge(int i, int n) {
    if (i >= 2 && i <= n - 1)
        bridge[i] = abs(A[i] - A[i - 1]) + abs(A[i] - A[i + 1]);
}

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = bridge[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

void update(int node, int l, int r, int idx) {

    if (l == r) {
        seg[node] = bridge[idx];
        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid)
        update(node * 2, l, mid, idx);
    else
        update(node * 2 + 1, mid + 1, r, idx);

    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
}

int main() {

    int n, q;

    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    for (int i = 2; i <= n - 1; i++)
        computeBridge(i, n);

    build(1, 2, n - 1);

    while (q--) {

        int type;
        scanf("%d", &type);

        if (type == 1) {

            int idx, x;
            scanf("%d%d", &idx, &x);

            A[idx] = x;

            for (int i = idx - 1; i <= idx + 1; i++) {
                if (i >= 2 && i <= n - 1) {
                    computeBridge(i, n);
                    update(1, 2, n - 1, i);
                }
            }
        }
        else {

            printf("%d\n", seg[1]);
        }
    }

    return 0;
}
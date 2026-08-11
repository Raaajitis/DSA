#include <stdio.h>

#define MAXN 100005

typedef struct {
    int len;
    int pref;
    int suff;
    long long score;
} Node;

Node tree[4 * MAXN];
int a[MAXN];

Node merge(Node left, Node right) {

    Node result;

    result.len = left.len + right.len;

    /*
     * Prefix of ones
     */
    result.pref = left.pref;

    if (left.pref == left.len)
        result.pref = left.len + right.pref;

    /*
     * Suffix of ones
     */
    result.suff = right.suff;

    if (right.suff == right.len)
        result.suff = right.len + left.suff;

    /*
     * Scores of islands completely inside
     * the two segments.
     */
    result.score = left.score + right.score;

    /*
     * If the left suffix and right prefix
     * are both non-zero, they form one island.
     *
     * Their old contributions were:
     *
     * left.suff² + right.pref²
     *
     * New contribution:
     *
     * (left.suff + right.pref)²
     */
    if (left.suff > 0 && right.pref > 0) {

        result.score +=
            2LL * left.suff * right.pref;
    }

    return result;
}

void build(int node, int l, int r) {

    if (l == r) {

        tree[node].len = 1;

        if (a[l] == 1) {
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].score = 1;
        } else {
            tree[node].pref = 0;
            tree[node].suff = 0;
            tree[node].score = 0;
        }

        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    tree[node] =
        merge(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int l, int r, int pos) {

    if (l == r) {

        a[pos] ^= 1;

        if (a[pos] == 1) {
            tree[node].pref = 1;
            tree[node].suff = 1;
            tree[node].score = 1;
        } else {
            tree[node].pref = 0;
            tree[node].suff = 0;
            tree[node].score = 0;
        }

        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(node * 2, l, mid, pos);
    else
        update(node * 2 + 1, mid + 1, r, pos);

    tree[node] =
        merge(tree[node * 2], tree[node * 2 + 1]);
}

int main() {

    int n, q;

    scanf("%d %d", &n, &q);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    build(1, 1, n);

    while (q--) {

        int type;
        scanf("%d", &type);

        if (type == 1) {

            int i;
            scanf("%d", &i);

            update(1, 1, n, i);

        } else if (type == 2) {

            printf("%lld\n", tree[1].score);
        }
    }

    return 0;
}
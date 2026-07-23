#include <stdio.h>

#define MAXN 100005

typedef struct {
    int len;
    int pre1, suf1, best1;
    int pre0, suf0, best0;
    int lazy;
} Node;

Node tree[4 * MAXN];
int arr[MAXN];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void merge(int idx) {
    Node *L = &tree[idx * 2];
    Node *R = &tree[idx * 2 + 1];
    Node *T = &tree[idx];

    T->len = L->len + R->len;

    // Ones
    T->pre1 = (L->pre1 == L->len) ? L->len + R->pre1 : L->pre1;
    T->suf1 = (R->suf1 == R->len) ? R->len + L->suf1 : R->suf1;
    T->best1 = max(max(L->best1, R->best1), L->suf1 + R->pre1);

    // Zeros
    T->pre0 = (L->pre0 == L->len) ? L->len + R->pre0 : L->pre0;
    T->suf0 = (R->suf0 == R->len) ? R->len + L->suf0 : R->suf0;
    T->best0 = max(max(L->best0, R->best0), L->suf0 + R->pre0);
}

void applyFlip(int idx) {
    Node *T = &tree[idx];

    int temp;

    temp = T->pre1;  T->pre1 = T->pre0;  T->pre0 = temp;
    temp = T->suf1;  T->suf1 = T->suf0;  T->suf0 = temp;
    temp = T->best1; T->best1 = T->best0; T->best0 = temp;

    T->lazy ^= 1;
}

void push(int idx) {
    if (tree[idx].lazy) {
        applyFlip(idx * 2);
        applyFlip(idx * 2 + 1);
        tree[idx].lazy = 0;
    }
}

void build(int idx, int l, int r) {

    tree[idx].lazy = 0;
    tree[idx].len = r - l + 1;

    if (l == r) {
        if (arr[l] == 1) {
            tree[idx].pre1 = tree[idx].suf1 = tree[idx].best1 = 1;
            tree[idx].pre0 = tree[idx].suf0 = tree[idx].best0 = 0;
        } else {
            tree[idx].pre0 = tree[idx].suf0 = tree[idx].best0 = 1;
            tree[idx].pre1 = tree[idx].suf1 = tree[idx].best1 = 0;
        }
        return;
    }

    int mid = (l + r) / 2;

    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    merge(idx);
}

void update(int idx, int l, int r, int ql, int qr) {

    if (ql <= l && r <= qr) {
        applyFlip(idx);
        return;
    }

    push(idx);

    int mid = (l + r) / 2;

    if (ql <= mid)
        update(idx * 2, l, mid, ql, qr);

    if (qr > mid)
        update(idx * 2 + 1, mid + 1, r, ql, qr);

    merge(idx);
}

int main() {

    int n;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    build(1, 1, n);

    int q;

    scanf("%d", &q);

    while (q--) {

        int l, r;

        scanf("%d%d", &l, &r);

        update(1, 1, n, l, r);

        printf("%d\n", tree[1].best1);
    }

    return 0;
}
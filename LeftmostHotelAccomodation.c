#include <stdio.h>
#include <stdlib.h>

long long maximum(long long a, long long b) {
    return a > b ? a : b;
}

void buildTree(
    long long *tree,
    const long long *capacity,
    int node,
    int left,
    int right
) {
    if (left == right) {
        tree[node] = capacity[left];
        return;
    }

    int middle = left + (right - left) / 2;

    buildTree(tree, capacity, node * 2, left, middle);
    buildTree(tree, capacity, node * 2 + 1, middle + 1, right);

    tree[node] = maximum(
        tree[node * 2],
        tree[node * 2 + 1]
    );
}

int allocateRooms(
    long long *tree,
    int node,
    int left,
    int right,
    long long required
) {
    if (left == right) {
        tree[node] -= required;
        return left;
    }

    int middle = left + (right - left) / 2;
    int hotelIndex;

    if (tree[node * 2] >= required) {
        hotelIndex = allocateRooms(
            tree,
            node * 2,
            left,
            middle,
            required
        );
    } else {
        hotelIndex = allocateRooms(
            tree,
            node * 2 + 1,
            middle + 1,
            right,
            required
        );
    }

    tree[node] = maximum(
        tree[node * 2],
        tree[node * 2 + 1]
    );

    return hotelIndex;
}

int main(void) {
    int n, q;
    scanf("%d %d", &n, &q);

    long long *capacity =
        malloc(n * sizeof(long long));

    long long *tree =
        malloc(4 * n * sizeof(long long));

    for (int i = 0; i < n; i++) {
        scanf("%lld", &capacity[i]);
    }

    buildTree(tree, capacity, 1, 0, n - 1);

    for (int i = 0; i < q; i++) {
        long long required;
        scanf("%lld", &required);

        int answer = 0;

        if (tree[1] >= required) {
            answer = allocateRooms(
                tree,
                1,
                0,
                n - 1,
                required
            ) + 1;
        }

        printf("%d%s", answer, i == q - 1 ? "\n" : " ");
    }

    free(capacity);
    free(tree);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Trie {
    struct Trie* child[2];
};

struct Trie* newNode() {
    struct Trie* t = (struct Trie*)malloc(sizeof(struct Trie));
    t->child[0] = t->child[1] = NULL;
    return t;
}

void insert(struct Trie* root, int num) {
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!root->child[bit])
            root->child[bit] = newNode();
        root = root->child[bit];
    }
}

int query(struct Trie* root, int num) {
    int res = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int want = 1 - bit;
        if (root->child[want]) {
            res |= (1 << i);
            root = root->child[want];
        } else {
            root = root->child[bit];
        }
    }
    return res;
}

int maxXORSubarray(int arr[], int n) {
    struct Trie* root = newNode();
    insert(root, 0);
    
    int prefix = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        prefix ^= arr[i];
        int q = query(root, prefix);
        if (q > ans) ans = q;
        insert(root, prefix);
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 7, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max XOR Subarray = %d\n", maxXORSubarray(arr, n));
    return 0;
}
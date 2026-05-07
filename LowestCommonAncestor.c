#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {

    struct Node* n =
        (struct Node*)malloc(sizeof(struct Node));

    n->data = data;
    n->left = n->right = NULL;

    return n;
}

struct Node* LCA(struct Node* root,
                 int p, int q) {

    if (root == NULL)
        return NULL;

    if (root->data == p ||
        root->data == q)
        return root;

    struct Node* left =
        LCA(root->left, p, q);

    struct Node* right =
        LCA(root->right, p, q);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main() {

    struct Node* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);

    root->left->left = createNode(6);
    root->left->right = createNode(2);

    struct Node* ans = LCA(root,6,2);

    printf("LCA: %d\n", ans->data);

    return 0;
}
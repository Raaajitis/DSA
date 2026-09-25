#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {

    struct Node *node =
        (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct Node* findLCA(struct Node *root,
                     struct Node *p,
                     struct Node *q) {

    if (root == NULL)
        return NULL;

    if (root == p || root == q)
        return root;

    struct Node *left =
        findLCA(root->left, p, q);

    struct Node *right =
        findLCA(root->right, p, q);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;

    return right;
}

int main() {

    struct Node *root = createNode(3);

    root->left = createNode(5);
    root->right = createNode(1);

    root->left->left = createNode(6);
    root->left->right = createNode(2);

    root->right->left = createNode(0);
    root->right->right = createNode(8);

    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);

    struct Node *p = root->left;
    struct Node *q = root->left->right->right;

    struct Node *lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("Lowest Common Ancestor: %d\n",
               lca->data);

    return 0;
}
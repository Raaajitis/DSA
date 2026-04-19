#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void leftBoundary(struct Node* root) {
    while (root) {
        if (root->left || root->right)
            printf("%d ", root->data);
        if (root->left)
            root = root->left;
        else
            root = root->right;
    }
}

void leaves(struct Node* root) {
    if (!root) return;

    leaves(root->left);

    if (!root->left && !root->right)
        printf("%d ", root->data);

    leaves(root->right);
}

void rightBoundary(struct Node* root) {
    int stack[100], top = -1;

    while (root) {
        if (root->left || root->right)
            stack[++top] = root->data;

        if (root->right)
            root = root->right;
        else
            root = root->left;
    }

    while (top != -1)
        printf("%d ", stack[top--]);
}

void boundary(struct Node* root) {

    if (!root) return;

    printf("%d ", root->data);

    leftBoundary(root->left);
    leaves(root->left);
    leaves(root->right);
    rightBoundary(root->right);
}

int main() {

    struct Node* root = create(20);
    root->left = create(8);
    root->right = create(22);
    root->left->left = create(4);
    root->left->right = create(12);
    root->left->right->left = create(10);
    root->left->right->right = create(14);
    root->right->right = create(25);

    boundary(root);

    return 0;
}
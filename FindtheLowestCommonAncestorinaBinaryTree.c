#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;

    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* findLCA(struct Node *root, int a, int b) {

    // Base case
    if (root == NULL) {
        return NULL;
    }

    // Current node is one of the required nodes
    if (root->data == a || root->data == b) {
        return root;
    }

    // Search left and right subtrees
    struct Node *left =
        findLCA(root->left, a, b);

    struct Node *right =
        findLCA(root->right, a, b);

    // One node found on each side
    if (left != NULL && right != NULL) {
        return root;
    }

    // Return whichever side found a node
    if (left != NULL) {
        return left;
    }

    return right;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);

    int a = 8;
    int b = 9;

    struct Node *result = findLCA(root, a, b);

    if (result != NULL) {

        printf("Lowest Common Ancestor of %d and %d is %d\n",
               a, b, result->data);

    } else {

        printf("Lowest Common Ancestor not found.\n");
    }

    return 0;
}
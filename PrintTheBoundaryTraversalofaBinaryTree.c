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

int isLeaf(struct Node *node) {

    return node != NULL &&
           node->left == NULL &&
           node->right == NULL;
}

void printLeftBoundary(struct Node *root) {

    struct Node *current = root->left;

    while (current != NULL) {

        if (!isLeaf(current)) {
            printf("%d ", current->data);
        }

        if (current->left != NULL) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
}

void printLeaves(struct Node *root) {

    if (root == NULL) {
        return;
    }

    if (isLeaf(root)) {

        printf("%d ", root->data);
        return;
    }

    printLeaves(root->left);
    printLeaves(root->right);
}

void printRightBoundary(struct Node *root) {

    if (root == NULL) {
        return;
    }

    struct Node *current;

    if (root->right != NULL) {
        current = root->right;
    }
    else {
        current = root->left;
    }

    if (current == NULL || isLeaf(current)) {
        return;
    }

    // Recursive call first
    printRightBoundary(current);

    // Print while returning
    printf("%d ", current->data);
}

void boundaryTraversal(struct Node *root) {

    if (root == NULL) {
        return;
    }

    printf("Boundary traversal: ");

    // Root
    printf("%d ", root->data);

    if (isLeaf(root)) {
        printf("\n");
        return;
    }

    // Left boundary
    printLeftBoundary(root);

    // Leaf nodes
    printLeaves(root);

    // Right boundary in reverse
    printRightBoundary(root);

    printf("\n");
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

    root->right->right->right = createNode(10);

    boundaryTraversal(root);

    return 0;
}
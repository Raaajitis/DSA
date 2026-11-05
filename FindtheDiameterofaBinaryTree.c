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

int max(int a, int b) {

    return (a > b) ? a : b;
}

int calculateHeight(struct Node *root,
                    int *diameter) {

    if (root == NULL) {
        return 0;
    }

    int leftHeight =
        calculateHeight(root->left, diameter);

    int rightHeight =
        calculateHeight(root->right, diameter);

    // Longest path passing through this node
    int currentDiameter =
        leftHeight + rightHeight;

    if (currentDiameter > *diameter) {
        *diameter = currentDiameter;
    }

    // Return height to parent
    return 1 + max(leftHeight, rightHeight);
}

int findDiameter(struct Node *root) {

    int diameter = 0;

    calculateHeight(root, &diameter);

    return diameter;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->left->left->left = createNode(6);

    root->left->right->right = createNode(7);

    int result = findDiameter(root);

    printf("Diameter of the tree: %d\n", result);

    return 0;
}
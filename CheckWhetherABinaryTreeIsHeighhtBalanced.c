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

    if (a > b)
        return a;

    return b;
}

int checkHeight(struct Node *root) {

    // Empty tree has height 0
    if (root == NULL) {
        return 0;
    }

    int leftHeight = checkHeight(root->left);

    // Left subtree is already unbalanced
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = checkHeight(root->right);

    // Right subtree is already unbalanced
    if (rightHeight == -1) {
        return -1;
    }

    int difference = leftHeight - rightHeight;

    if (difference < 0) {
        difference = -difference;
    }

    // Current node is unbalanced
    if (difference > 1) {
        return -1;
    }

    return 1 + max(leftHeight, rightHeight);
}

int isBalanced(struct Node *root) {

    if (checkHeight(root) == -1) {
        return 0;
    }

    return 1;
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    if (isBalanced(root)) {

        printf("The tree is balanced.\n");

    } else {

        printf("The tree is not balanced.\n");
    }

    return 0;
}
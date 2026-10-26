#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int validateBST(struct Node *root,
                long long minimum,
                long long maximum) {

    if (root == NULL) {
        return 1;
    }

    // Current value must lie strictly inside range
    if (root->data <= minimum ||
        root->data >= maximum) {

        return 0;
    }

    // Check left and right subtrees
    return validateBST(
               root->left,
               minimum,
               root->data
           )
           &&
           validateBST(
               root->right,
               root->data,
               maximum
           );
}

int isValidBST(struct Node *root) {

    return validateBST(
        root,
        LLONG_MIN,
        LLONG_MAX
    );
}

int main() {

    struct Node *root = createNode(8);

    root->left = createNode(3);
    root->right = createNode(10);

    root->left->left = createNode(1);
    root->left->right = createNode(6);

    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);

    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    if (isValidBST(root)) {

        printf("The tree is a valid BST.\n");

    } else {

        printf("The tree is not a valid BST.\n");
    }

    return 0;
}
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

int max(int a, int b) {

    return (a > b) ? a : b;
}

int findMaxPath(struct Node *root, int *answer) {

    // Leaf node
    if (root->left == NULL &&
        root->right == NULL) {

        return root->data;
    }

    // Only right child exists
    if (root->left == NULL) {

        return root->data +
               findMaxPath(root->right, answer);
    }

    // Only left child exists
    if (root->right == NULL) {

        return root->data +
               findMaxPath(root->left, answer);
    }

    // Both children exist
    int leftSum =
        findMaxPath(root->left, answer);

    int rightSum =
        findMaxPath(root->right, answer);

    int currentPath =
        leftSum + root->data + rightSum;

    if (currentPath > *answer) {
        *answer = currentPath;
    }

    return root->data +
           max(leftSum, rightSum);
}

int maximumLeafPath(struct Node *root) {

    if (root == NULL) {
        return 0;
    }

    int answer = INT_MIN;

    int rootToLeaf =
        findMaxPath(root, &answer);

    /*
       If there aren't two leaves, a true
       leaf-to-leaf path doesn't exist.
       For this example, the tree has multiple leaves.
    */

    if (answer == INT_MIN) {
        return rootToLeaf;
    }

    return answer;
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(2);
    root->right = createNode(10);

    root->left->left = createNode(20);
    root->left->right = createNode(1);

    root->right->right = createNode(-25);

    root->right->right->left = createNode(3);
    root->right->right->right = createNode(4);

    int result = maximumLeafPath(root);

    printf("Maximum leaf-to-leaf path sum: %d\n",
           result);

    return 0;
}
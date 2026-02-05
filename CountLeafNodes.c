#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to count leaf nodes
int countLeafNodes(struct node *root) {
    if (root == NULL) {
        return 0;
    }

    // If node has no children, it is a leaf
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    // Count leaf nodes in left and right subtree
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    // Create tree
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 10;

    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 20;
    root->left->left = NULL;
    root->left->right = NULL;

    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 30;
    root->right->left = NULL;
    root->right->right = NULL;

    // Print leaf node count
    printf("Leaf nodes: %d", countLeafNodes(root));

    return 0;
}

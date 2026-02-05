#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to count total nodes
int countNodes(struct node *root) {
    if (root == NULL) {
        return 0; // No node
    }

    // Count current node + left subtree + right subtree
    return 1 + countNodes(root->left) + countNodes(root->right);
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

    // Print total node count
    printf("Total nodes: %d", countNodes(root));

    return 0;
}

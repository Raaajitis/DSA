#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Tree node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to check BST
int isBSTUtil(struct node* root, int min, int max) {

    if (root == NULL)
        return 1;

    // If node violates BST property
    if (root->data <= min || root->data >= max)
        return 0;

    // Check left and right subtree with updated limits
    return isBSTUtil(root->left, min, root->data) &&
           isBSTUtil(root->right, root->data, max);
}

// Main BST check function
int isBST(struct node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {

    // Create BST
    struct node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);

    if (isBST(root))
        printf("Tree is a BST");
    else
        printf("Tree is NOT a BST");

    return 0;
}

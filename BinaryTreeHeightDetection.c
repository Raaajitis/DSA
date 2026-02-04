#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to find the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function for calculating the height of tree
int height(struct node *root) {
    if (root == NULL) {
        return 0; // Empty tree's height is 0
    }

    // Finding height of left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Returning max height + 1 (for current node)
    return 1 + max(leftHeight, rightHeight);
}

int main() {
    // Creating tree
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

    // Printing height
    printf("Height of tree is: %d", height(root));

    return 0;
}

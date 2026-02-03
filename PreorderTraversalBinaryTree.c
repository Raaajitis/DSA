#include <stdio.h>
#include <stdlib.h>

// Binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Preorder traversal function
void preorder(struct node *root) {
    if (root == NULL) {
        return; // Base case
    }

    printf("%d ", root->data);  // Visiting root
    preorder(root->left);       // Visiting left subtree
    preorder(root->right);      // Visiting right subtree
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

    // Printing preorder traversal
    preorder(root);

    return 0;
}

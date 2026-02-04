#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Postorder traversal function
void postorder(struct node *root) {
    if (root == NULL) {
        return; 
    }

    postorder(root->left);       // Visiting left subtree
    postorder(root->right);      // Visiting right subtree
    printf("%d ", root->data);   // Visiting root
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

    // Printing postorder traversal
    postorder(root);

    return 0;
}

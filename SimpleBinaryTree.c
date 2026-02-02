#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

int main() {
    // Creating root
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = 10;

    // Creating left child
    root->left = (struct node *)malloc(sizeof(struct node));
    root->left->data = 20;
    root->left->left = NULL;
    root->left->right = NULL;

    // Creating right child
    root->right = (struct node *)malloc(sizeof(struct node));
    root->right->data = 30;
    root->right->left = NULL;
    root->right->right = NULL;

    // Printing values
    printf("Root: %d\n", root->data);
    printf("Left child: %d\n", root->left->data);
    printf("Right child: %d\n", root->right->data);

    return 0;
}

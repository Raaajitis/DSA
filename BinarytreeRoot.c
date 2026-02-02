#include <stdio.h>
#include <stdlib.h>

// Structure of a binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

int main() {
    // Creating root node
    struct node *root = (struct node *)malloc(sizeof(struct node));

    // Assigning values
    root->data = 10;
    root->left = NULL;
    root->right = NULL;

    // Printing root value
    printf("Root node value: %d", root->data);

    return 0;
}

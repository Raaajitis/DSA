#include <stdio.h>
#include <stdlib.h>

// BST Node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find Minimum value in BST
int findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Find Maximum value in BST
int findMax(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    struct node* root = NULL;

    // Build BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);

    printf("Minimum value: %d\n", findMin(root));
    printf("Maximum value: %d\n", findMax(root));

    return 0;
}

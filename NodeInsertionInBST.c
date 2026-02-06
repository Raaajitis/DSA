#include <stdio.h>
#include <stdlib.h>

// BST node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Creating a new node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserting a value in BST
struct node* insert(struct node* root, int value) {

    // If tree is empty, new node becomes root
    if (root == NULL) {
        return createNode(value);
    }

    // If value is smaller, going to the left
    if (value < root->data) {
        root->left = insert(root->left, value);
    }

    // If value is greater, going to the right
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Inorder traversal (to print sorted order)
void inorder(struct node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;

    // Inserting nodes
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);

    printf("BST Inorder Traversal: ");
    inorder(root);

    return 0;
}

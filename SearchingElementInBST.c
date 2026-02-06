#include <stdio.h>
#include <stdlib.h>

// BST node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Creating node function
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inserting node in BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Searching function in BST
int search(struct node* root, int key) {

    // If tree is empty
    if (root == NULL)
        return 0;

    // If key is found
    if (root->data == key)
        return 1;

    // Searching in left subtree
    if (key < root->data)
        return search(root->left, key);

    // Searching in right subtree
    return search(root->right, key);
}

int main() {
    struct node* root = NULL;

    // Creating BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);

    int key = 25;

    if (search(root, key))
        printf("Element %d found in BST!", key);
    else
        printf("Element %d not found in BST!", key);

    return 0;
}

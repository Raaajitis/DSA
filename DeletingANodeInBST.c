#include <stdio.h>
#include <stdlib.h>

// BST Node structure
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

// Insert in BST
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum node (used in deletion)
struct node* findMinNode(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node in BST
struct node* deleteNode(struct node* root, int key) {

    if (root == NULL)
        return root;

    // Go left if key is smaller
    if (key < root->data)
        root->left = deleteNode(root->left, key);

    // Go right if key is larger
    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    // Node found
    else {

        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct node* temp = findMinNode(root->right);

        // Replace root value with successor value
        root->data = temp->data;

        // Delete successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(struct node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = NULL;

    // Build BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 25);

    printf("Before deletion (Inorder): ");
    inorder(root);

    // Delete node
    root = deleteNode(root, 20);

    printf("\nAfter deletion (Inorder): ");
    inorder(root);

    return 0;
}

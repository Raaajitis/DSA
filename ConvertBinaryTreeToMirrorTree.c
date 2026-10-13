#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;

    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void mirrorTree(struct Node *root) {

    // Base case
    if (root == NULL) {
        return;
    }

    // Mirror both subtrees
    mirrorTree(root->left);
    mirrorTree(root->right);

    // Swap left and right children
    struct Node *temp = root->left;

    root->left = root->right;

    root->right = temp;
}

void inorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    printf("Inorder before mirroring:\n");
    inorder(root);

    mirrorTree(root);

    printf("\n\nInorder after mirroring:\n");
    inorder(root);

    printf("\n");

    return 0;
}
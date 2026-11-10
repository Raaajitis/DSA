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

void detectSwappedNodes(
    struct Node *root,
    struct Node **previous,
    struct Node **first,
    struct Node **second) {

    if (root == NULL) {
        return;
    }

    // Inorder: Left
    detectSwappedNodes(
        root->left,
        previous,
        first,
        second
    );

    // Inorder: Root
    if (*previous != NULL &&
        (*previous)->data > root->data) {

        if (*first == NULL) {

            // First violation
            *first = *previous;
            *second = root;

        } else {

            // Second violation
            *second = root;
        }
    }

    *previous = root;

    // Inorder: Right
    detectSwappedNodes(
        root->right,
        previous,
        first,
        second
    );
}

void recoverBST(struct Node *root) {

    struct Node *previous = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;

    detectSwappedNodes(
        root,
        &previous,
        &first,
        &second
    );

    if (first != NULL && second != NULL) {

        int temp = first->data;

        first->data = second->data;
        second->data = temp;
    }
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

    struct Node *root = createNode(6);

    /*
        Corrupted BST:

              6
             / \
            8   3
           / \ / \
          1  4 7  10
    */

    root->left = createNode(8);
    root->right = createNode(3);

    root->left->left = createNode(1);
    root->left->right = createNode(4);

    root->right->left = createNode(7);
    root->right->right = createNode(10);

    printf("Inorder before recovery:\n");
    inorder(root);

    recoverBST(root);

    printf("\n\nInorder after recovery:\n");
    inorder(root);

    printf("\n");

    return 0;
}
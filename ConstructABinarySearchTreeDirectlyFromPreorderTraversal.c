#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

struct Node* buildBST(int preorder[],
                      int n,
                      int *index,
                      long long minimum,
                      long long maximum) {

    if (*index >= n) {
        return NULL;
    }

    int value = preorder[*index];

    /*
     * Current preorder value does not
     * belong to this subtree.
     */
    if (value <= minimum ||
        value >= maximum) {

        return NULL;
    }

    struct Node *root =
        createNode(value);

    (*index)++;

    /*
     * Values in the left subtree must
     * lie between minimum and root.
     */
    root->left =
        buildBST(
            preorder,
            n,
            index,
            minimum,
            value
        );

    /*
     * Values in the right subtree must
     * lie between root and maximum.
     */
    root->right =
        buildBST(
            preorder,
            n,
            index,
            value,
            maximum
        );

    return root;
}

struct Node* bstFromPreorder(int preorder[],
                             int n) {

    int index = 0;

    return buildBST(
        preorder,
        n,
        &index,
        LLONG_MIN,
        LLONG_MAX
    );
}

void inorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

void preorderPrint(struct Node *root) {

    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);

    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {

    int preorder[] = {
        8, 5, 1, 7, 10, 12
    };

    int n =
        sizeof(preorder) / sizeof(preorder[0]);

    struct Node *root =
        bstFromPreorder(preorder, n);

    printf("Inorder traversal:\n");
    inorder(root);

    printf("\n\nPreorder traversal:\n");
    preorderPrint(root);

    printf("\n");

    return 0;
}
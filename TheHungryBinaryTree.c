#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

void absorb(struct Node* root) {

    if(root == NULL)
        return;

    absorb(root->left);
    absorb(root->right);

    struct Node* best = NULL;

    if(root->left && root->right) {
        best = (root->left->data > root->right->data)
             ? root->left : root->right;
    }
    else if(root->left)
        best = root->left;
    else if(root->right)
        best = root->right;

    if(best) {
        root->data += best->data;
        best->data = 0;
    }
}

void preorder(struct Node* root) {
    if(root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {

    struct Node* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(2);

    absorb(root);

    preorder(root);

    return 0;
}
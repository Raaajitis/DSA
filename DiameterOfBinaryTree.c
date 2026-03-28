#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int diameter = 0;

int height(struct Node* root) {

    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    if (left + right > diameter)
        diameter = left + right;

    return 1 + max(left, right);
}

int findDiameter(struct Node* root) {
    diameter = 0;
    height(root);
    return diameter;
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Diameter: %d\n", findDiameter(root));

    return 0;
}
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

int count = 0;
int result = -1;

void inorder(struct Node* root, int k) {

    if (!root || count >= k)
        return;

    inorder(root->left, k);

    count++;
    if (count == k) {
        result = root->data;
        return;
    }

    inorder(root->right, k);
}

int kthSmallest(struct Node* root, int k) {
    count = 0;
    result = -1;
    inorder(root, k);
    return result;
}

int main() {

    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(6);
    root->left->left = createNode(2);
    root->left->right = createNode(4);

    int k = 3;

    printf("Kth Smallest: %d\n", kthSmallest(root, k));

    return 0;
}
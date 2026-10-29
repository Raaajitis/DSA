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

void kthSmallestHelper(struct Node *root,
                       int k,
                       int *count,
                       int *answer) {

    if (root == NULL || *count >= k) {
        return;
    }

    // Visit left subtree
    kthSmallestHelper(
        root->left,
        k,
        count,
        answer
    );

    if (*count >= k) {
        return;
    }

    // Visit current node
    (*count)++;

    if (*count == k) {

        *answer = root->data;
        return;
    }

    // Visit right subtree
    kthSmallestHelper(
        root->right,
        k,
        count,
        answer
    );
}

int kthSmallest(struct Node *root, int k) {

    int count = 0;
    int answer = -1;

    kthSmallestHelper(
        root,
        k,
        &count,
        &answer
    );

    return answer;
}

int main() {

    struct Node *root = createNode(8);

    root->left = createNode(3);
    root->right = createNode(10);

    root->left->left = createNode(1);
    root->left->right = createNode(6);

    root->left->right->left = createNode(4);
    root->left->right->right = createNode(7);

    root->right->right = createNode(14);
    root->right->right->left = createNode(13);

    int k = 4;

    int result = kthSmallest(root, k);

    if (result == -1) {

        printf("Invalid value of k.\n");

    } else {

        printf("%dth smallest element: %d\n",
               k, result);
    }

    return 0;
}
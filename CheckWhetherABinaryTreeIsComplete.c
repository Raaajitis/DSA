#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

int isComplete(struct Node *root) {

    if (root == NULL) {
        return 1;
    }

    struct Node *queue[MAX];

    int front = 0;
    int rear = 0;

    int mustBeLeaf = 0;

    queue[rear++] = root;

    while (front < rear) {

        struct Node *current = queue[front++];

        // Process left child
        if (current->left != NULL) {

            if (mustBeLeaf) {
                return 0;
            }

            queue[rear++] = current->left;

        } else {

            mustBeLeaf = 1;
        }

        // Process right child
        if (current->right != NULL) {

            if (mustBeLeaf) {
                return 0;
            }

            queue[rear++] = current->right;

        } else {

            mustBeLeaf = 1;
        }
    }

    return 1;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);

    if (isComplete(root)) {

        printf("The tree is complete.\n");

    } else {

        printf("The tree is not complete.\n");
    }

    return 0;
}
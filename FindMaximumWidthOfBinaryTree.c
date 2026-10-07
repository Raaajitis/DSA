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

int maximumWidth(struct Node *root) {

    if (root == NULL) {
        return 0;
    }

    struct Node *queue[MAX];

    int front = 0;
    int rear = 0;

    int maxWidth = 0;

    queue[rear++] = root;

    while (front < rear) {

        int levelSize = rear - front;

        if (levelSize > maxWidth) {
            maxWidth = levelSize;
        }

        for (int i = 0; i < levelSize; i++) {

            struct Node *current = queue[front++];

            if (current->left != NULL) {
                queue[rear++] = current->left;
            }

            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
    }

    return maxWidth;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(8);

    root->right->right->left = createNode(6);
    root->right->right->right = createNode(7);

    int result = maximumWidth(root);

    printf("Maximum width of the tree: %d\n", result);

    return 0;
}
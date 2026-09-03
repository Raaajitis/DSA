#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct QueueNode {
    struct Node *node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct QueueNode queue[100];
    int front = 0;
    int rear = 0;

    int values[100][100];
    int count[100] = {0};

    int offset = 50;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    int minHD = 0;
    int maxHD = 0;

    while (front < rear) {
        struct QueueNode current = queue[front++];

        struct Node* node = current.node;
        int hd = current.hd;

        values[hd + offset][count[hd + offset]++] = node->data;

        if (hd < minHD)
            minHD = hd;

        if (hd > maxHD)
            maxHD = hd;

        if (node->left != NULL) {
            queue[rear].node = node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (node->right != NULL) {
            queue[rear].node = node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    printf("Vertical Order:\n");

    for (int hd = minHD; hd <= maxHD; hd++) {
        printf("[ ");

        for (int i = 0; i < count[hd + offset]; i++)
            printf("%d ", values[hd + offset][i]);

        printf("]\n");
    }
}

int main() {
    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    verticalOrder(root);

    return 0;
}
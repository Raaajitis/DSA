#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create(int x) {

    struct Node* n =
        (struct Node*)malloc(sizeof(struct Node));

    n->data = x;
    n->left = n->right = NULL;

    return n;
}

void mirrorLevels(struct Node* root) {

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 0;

    while (front < rear) {

        int size = rear - front;
        int temp[100];

        for (int i = 0; i < size; i++) {

            struct Node* curr = queue[front++];

            temp[i] = curr->data;

            if (curr->left)
                queue[rear++] = curr->left;

            if (curr->right)
                queue[rear++] = curr->right;
        }

        if (level % 2 == 1) {

            for (int i = size - 1; i >= 0; i--)
                printf("%d ", temp[i]);
        }
        else {

            for (int i = 0; i < size; i++)
                printf("%d ", temp[i]);
        }

        printf("\n");
        level++;
    }
}

int main() {

    struct Node* root = create(1);

    root->left = create(2);
    root->right = create(3);

    root->left->left = create(4);
    root->left->right = create(5);

    root->right->left = create(6);
    root->right->right = create(7);

    mirrorLevels(root);

    return 0;
}
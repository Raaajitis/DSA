#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void diagonal(struct Node* root) {

    if (!root) return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        int size = rear - front;

        while (size--) {

            struct Node* curr = queue[front++];

            while (curr) {
                printf("%d ", curr->data);

                if (curr->left)
                    queue[rear++] = curr->left;

                curr = curr->right;
            }
        }

        printf("\n");
    }
}

int main() {

    struct Node* root = create(8);
    root->left = create(3);
    root->right = create(10);
    root->left->left = create(1);
    root->left->right = create(6);
    root->right->right = create(14);
    root->left->right->left = create(4);
    root->left->right->right = create(7);
    root->right->right->left = create(13);

    diagonal(root);

    return 0;
}
#include <stdio.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void zigzag(struct Node* root) {

    if (!root) return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {

        int size = rear - front;
        int level[MAX];

        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];

            int index = leftToRight ? i : size - 1 - i;
            level[index] = curr->data;

            if (curr->left)
                queue[rear++] = curr->left;
            if (curr->right)
                queue[rear++] = curr->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", level[i]);
        printf("\n");

        leftToRight = !leftToRight;
    }
}

int main() {

    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);
    root->right->right = create(6);

    zigzag(root);

    return 0;
}
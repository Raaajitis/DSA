#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int x) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

void dfs(struct Node *root, int level, int effect) {

    if (root == NULL)
        return;

    root->data += effect;

    printf("%d ", root->data);

    int nextEffect;

    if (level % 2 == 1)
        nextEffect = effect + root->data;
    else
        nextEffect = effect - root->data;

    dfs(root->left, level + 1, nextEffect);
    dfs(root->right, level + 1, nextEffect);
}

int main() {

    struct Node *root = newNode(5);

    root->left = newNode(3);
    root->right = newNode(8);

    root->left->left = newNode(2);

    printf("Preorder After Pulse:\n");

    dfs(root, 1, 0);

    return 0;
}
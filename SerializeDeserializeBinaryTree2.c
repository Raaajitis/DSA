#include <stdio.h>
#include <stdlib.h>

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

void serialize(struct Node* root) {

    if (!root) {
        printf("# ");
        return;
    }

    printf("%d ", root->data);

    serialize(root->left);
    serialize(root->right);
}

int main() {

    struct Node* root = create(1);
    root->left = create(2);
    root->right = create(3);

    printf("Serialized Tree:\n");
    serialize(root);

    return 0;
}
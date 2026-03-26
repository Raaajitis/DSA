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

// Simple preorder serialization
void serialize(struct Node* root) {

    if (root == NULL) {
        printf("NULL ");
        return;
    }

    printf("%d ", root->data);
    serialize(root->left);
    serialize(root->right);
}

// Simple deserialization
struct Node* deserialize(int arr[], int *index, int n) {

    if (*index >= n || arr[*index] == -1) {
        (*index)++;
        return NULL;
    }

    struct Node* root = createNode(arr[*index]);
    (*index)++;

    root->left = deserialize(arr, index, n);
    root->right = deserialize(arr, index, n);

    return root;
}

void inorder(struct Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Serialized Tree: ");
    serialize(root);

    int arr[] = {1,2,-1,-1,3,-1,-1};
    int index = 0;

    struct Node* newRoot = deserialize(arr, &index, 7);

    printf("\nInorder of Deserialized Tree: ");
    inorder(newRoot);

    return 0;
}
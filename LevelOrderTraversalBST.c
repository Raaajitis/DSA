#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Queue structure (array based)
struct node* queue[100];
int front = -1, rear = -1;

// Enqueue function
void enqueue(struct node* temp) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = temp;
}

// Dequeue function
struct node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Create new tree node
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Level Order Traversal (BFS)
void levelOrder(struct node* root) {

    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear) {

        struct node* current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);

        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main() {

    // Create tree
    struct node* root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Level Order Traversal: ");
    levelOrder(root);

    return 0;
}

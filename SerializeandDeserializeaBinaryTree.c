#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

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

void serializeHelper(struct Node *root,
                     char result[]) {

    char temp[30];

    if (root == NULL) {

        strcat(result, "#,");
        return;
    }

    sprintf(temp, "%d,", root->data);

    strcat(result, temp);

    serializeHelper(root->left, result);
    serializeHelper(root->right, result);
}

void serialize(struct Node *root,
               char result[]) {

    result[0] = '\0';

    serializeHelper(root, result);
}

struct Node* deserializeHelper(char **token) {

    if (*token == NULL) {
        return NULL;
    }

    if (strcmp(*token, "#") == 0) {

        *token = strtok(NULL, ",");

        return NULL;
    }

    int value = atoi(*token);

    struct Node *root = createNode(value);

    *token = strtok(NULL, ",");

    root->left =
        deserializeHelper(token);

    root->right =
        deserializeHelper(token);

    return root;
}

struct Node* deserialize(char data[]) {

    char *token = strtok(data, ",");

    return deserializeHelper(&token);
}

void inorder(struct Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->right->left = createNode(40);
    root->right->right = createNode(50);

    char serialized[MAX];

    serialize(root, serialized);

    printf("Serialized Tree:\n");
    printf("%s\n", serialized);

    char copy[MAX];

    strcpy(copy, serialized);

    struct Node *newRoot =
        deserialize(copy);

    printf("\nInorder of reconstructed tree:\n");

    inorder(newRoot);

    printf("\n");

    return 0;
}
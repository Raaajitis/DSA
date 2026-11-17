#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define OFFSET 50

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

void calculateVerticalSum(
    struct Node *root,
    int horizontalDistance,
    int verticalSum[],
    int *minimumHD,
    int *maximumHD) {

    if (root == NULL) {
        return;
    }

    int index =
        horizontalDistance + OFFSET;

    verticalSum[index] += root->data;

    if (horizontalDistance < *minimumHD) {
        *minimumHD = horizontalDistance;
    }

    if (horizontalDistance > *maximumHD) {
        *maximumHD = horizontalDistance;
    }

    // Left child
    calculateVerticalSum(
        root->left,
        horizontalDistance - 1,
        verticalSum,
        minimumHD,
        maximumHD
    );

    // Right child
    calculateVerticalSum(
        root->right,
        horizontalDistance + 1,
        verticalSum,
        minimumHD,
        maximumHD
    );
}

void printVerticalSums(struct Node *root) {

    int verticalSum[MAX] = {0};

    int minimumHD = 0;
    int maximumHD = 0;

    calculateVerticalSum(
        root,
        0,
        verticalSum,
        &minimumHD,
        &maximumHD
    );

    printf("Vertical sums: ");

    for (int hd = minimumHD;
         hd <= maximumHD;
         hd++) {

        printf("%d ",
               verticalSum[hd + OFFSET]);
    }

    printf("\n");
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printVerticalSums(root);

    return 0;
}
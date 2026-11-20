#include <stdio.h>
#include <stdlib.h>

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

int findFrequency(long long sums[],
                  int frequencies[],
                  int count,
                  long long value) {

    for (int i = 0; i < count; i++) {

        if (sums[i] == value) {
            return frequencies[i];
        }
    }

    return 0;
}

void changeFrequency(long long sums[],
                     int frequencies[],
                     int *count,
                     long long value,
                     int change) {

    for (int i = 0; i < *count; i++) {

        if (sums[i] == value) {

            frequencies[i] += change;
            return;
        }
    }

    sums[*count] = value;
    frequencies[*count] = change;

    (*count)++;
}

int countPathsHelper(struct Node *root,
                     long long currentSum,
                     int k,
                     long long sums[],
                     int frequencies[],
                     int *prefixCount) {

    if (root == NULL) {
        return 0;
    }

    currentSum += root->data;

    long long required =
        currentSum - k;

    int paths =
        findFrequency(
            sums,
            frequencies,
            *prefixCount,
            required
        );

    /*
     * Add current prefix before
     * exploring children.
     */
    changeFrequency(
        sums,
        frequencies,
        prefixCount,
        currentSum,
        1
    );

    paths +=
        countPathsHelper(
            root->left,
            currentSum,
            k,
            sums,
            frequencies,
            prefixCount
        );

    paths +=
        countPathsHelper(
            root->right,
            currentSum,
            k,
            sums,
            frequencies,
            prefixCount
        );

    /*
     * Backtrack: remove this prefix
     * before returning to the parent.
     */
    changeFrequency(
        sums,
        frequencies,
        prefixCount,
        currentSum,
        -1
    );

    return paths;
}

int countPaths(struct Node *root, int k) {

    long long sums[MAX];
    int frequencies[MAX];

    int prefixCount = 1;

    /*
     * Prefix sum 0 exists once before
     * the root is visited.
     */
    sums[0] = 0;
    frequencies[0] = 1;

    return countPathsHelper(
        root,
        0,
        k,
        sums,
        frequencies,
        &prefixCount
    );
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(5);
    root->right = createNode(-3);

    root->left->left = createNode(3);
    root->left->right = createNode(2);

    root->right->right = createNode(11);

    root->left->left->left = createNode(3);
    root->left->left->right = createNode(-2);

    root->left->right->right = createNode(1);

    int k = 8;

    int result = countPaths(root, k);

    printf("Number of paths with sum %d: %d\n",
           k, result);

    return 0;
}
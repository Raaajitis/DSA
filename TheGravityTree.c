#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create(int x) {

    struct Node* n =
        malloc(sizeof(struct Node));

    n->data = x;
    n->left = n->right = NULL;

    return n;
}

void store(struct Node *root,
           int arr[],
           int *idx) {

    if(root == NULL)
        return;

    arr[(*idx)++] = root->data;

    store(root->left,arr,idx);
    store(root->right,arr,idx);
}

struct Node* build(int arr[],
                   int n,
                   int i) {

    if(i >= n)
        return NULL;

    struct Node* root =
        create(arr[i]);

    root->left =
        build(arr,n,2*i+1);

    root->right =
        build(arr,n,2*i+2);

    return root;
}

void levelOrder(struct Node* root) {

    struct Node* q[100];

    int f=0,r=0;

    q[r++] = root;

    while(f<r) {

        struct Node* cur =
            q[f++];

        printf("%d ",
               cur->data);

        if(cur->left)
            q[r++] = cur->left;

        if(cur->right)
            q[r++] = cur->right;
    }
}

int main() {

    struct Node* root =
        create(10);

    root->left =
        create(5);

    root->right =
        create(20);

    root->right->right =
        create(30);

    int arr[100];
    int n = 0;

    store(root,arr,&n);

    root = build(arr,n,0);

    levelOrder(root);

    return 0;
}
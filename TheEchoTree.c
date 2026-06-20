#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int x){

    struct Node *t=malloc(sizeof(struct Node));

    t->data=x;
    t->left=t->right=NULL;

    return t;
}

void dfs(struct Node *root,int parent,int grand){

    if(root==NULL)
        return;

    root->data = root->data + parent + grand;

    printf("%d ",root->data);

    dfs(root->left,root->data,parent);
    dfs(root->right,root->data,parent);
}

int main(){

    struct Node *root=newNode(5);

    root->left=newNode(3);
    root->right=newNode(8);

    root->left->left=newNode(2);

    dfs(root,0,0);

    return 0;
}
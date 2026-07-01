#include <stdio.h>
#include <stdlib.h>

typedef struct Node {

    int real;
    int ghost;

    struct Node *left;
    struct Node *right;

}Node;

Node* newNode(int real,int ghost){

    Node *temp=(Node*)malloc(sizeof(Node));

    temp->real=real;
    temp->ghost=ghost;

    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

Node* insert(Node *root,int real,int ghost,int depth){

    if(root==NULL)
        return newNode(real,ghost);

    if(depth%2==0){

        if(real<root->real)
            root->left=insert(root->left,real,ghost,depth+1);

        else
            root->right=insert(root->right,real,ghost,depth+1);
    }
    else{

        if(ghost<root->ghost)
            root->left=insert(root->left,real,ghost,depth+1);

        else
            root->right=insert(root->right,real,ghost,depth+1);
    }

    return root;
}

Node* search(Node *root,int real,int ghost,int depth){

    if(root==NULL)
        return NULL;

    if(root->real==real && root->ghost==ghost)
        return root;

    if(depth%2==0){

        if(real<root->real)
            return search(root->left,real,ghost,depth+1);

        else
            return search(root->right,real,ghost,depth+1);
    }
    else{

        if(ghost<root->ghost)
            return search(root->left,real,ghost,depth+1);

        else
            return search(root->right,real,ghost,depth+1);
    }
}

void inorder(Node *root){

    if(root==NULL)
        return;

    inorder(root->left);

    printf("(R=%d G=%d)\n",root->real,root->ghost);

    inorder(root->right);
}

int main(){

    Node *root=NULL;

    root=insert(root,40,15,0);
    root=insert(root,20,35,0);
    root=insert(root,60,10,0);
    root=insert(root,50,25,0);
    root=insert(root,70,5,0);

    printf("Tree:\n\n");

    inorder(root);

    Node *ans=search(root,50,25,0);

    if(ans)
        printf("\nFound Node : Real=%d Ghost=%d\n",ans->real,ans->ghost);
    else
        printf("\nNot Found\n");

    return 0;
}
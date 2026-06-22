#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left,*right;
};

struct Node* newNode(int x){
    struct Node* t = malloc(sizeof(struct Node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

int main(){

    struct Node* level[100];
    int size = 0;

    struct Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->right = newNode(14);

    struct Node* q[100];
    int front=0,rear=0;

    q[rear++] = root;

    while(front<rear){

        int cnt = rear-front;

        struct Node* nodes[100];

        for(int i=0;i<cnt;i++){
            nodes[i]=q[front++];

            if(nodes[i]->left)
                q[rear++]=nodes[i]->left;

            if(nodes[i]->right)
                q[rear++]=nodes[i]->right;
        }

        for(int i=0;i<cnt;i++){

            printf("%d -> ",nodes[i]->data);

            int found=0;

            for(int j=i+1;j<cnt;j++){

                if(nodes[j]->data > nodes[i]->data){

                    printf("%d",nodes[j]->data);
                    found=1;
                    break;
                }
            }

            if(!found)
                printf("NULL");

            printf("\n");
        }
    }

    return 0;
}
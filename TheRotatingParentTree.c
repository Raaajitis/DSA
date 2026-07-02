#include <stdio.h>

#define MAX 100

int value[MAX];
int parent[MAX];
int n;

int main(){

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d",&value[i]);

    for(int i=2;i<=n;i++)
        scanf("%d",&parent[i]);

    int changed;

    do{

        changed=0;

        for(int i=1;i<=n;i++){

            int best=-1;

            for(int j=2;j<=n;j++){

                if(parent[j]==i){

                    if(best==-1 || value[j]>value[best])
                        best=j;
                }
            }

            if(best!=-1 && parent[i]!=best){

                int oldParent=parent[i];

                parent[i]=best;
                parent[best]=oldParent;

                changed=1;
            }
        }

    }while(changed);

    printf("Final Parents\n");

    for(int i=2;i<=n;i++)
        printf("%d ",parent[i]);

    return 0;
}
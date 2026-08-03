#include <stdio.h>

#define MAX 1005

int parent[MAX];
int value[MAX];

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++)
        scanf("%d",&value[i]);

    parent[1]=0;

    for(int i=2;i<=n;i++)
        scanf("%d",&parent[i]);

    while(q--){

        int u;
        scanf("%d",&u);

        int mn=value[u];
        int mx=value[u];

        while(parent[u]){

            u=parent[u];

            if(value[u]<mn)
                mn=value[u];

            if(value[u]>mx)
                mx=value[u];
        }

        printf("%d\n",mx-mn);
    }

    return 0;
}
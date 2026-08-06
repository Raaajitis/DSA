#include <stdio.h>

#define MAX 1005

int parent[MAX];
int value[MAX];
int depth[MAX];

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++)
        scanf("%d",&value[i]);

    parent[1]=0;
    depth[1]=0;

    for(int i=2;i<=n;i++){

        scanf("%d",&parent[i]);
        depth[i]=depth[parent[i]]+1;
    }

    while(q--){

        int u,v;

        scanf("%d%d",&u,&v);

        while(depth[u]>depth[v])
            u=parent[u];

        while(depth[v]>depth[u])
            v=parent[v];

        while(u!=v){

            u=parent[u];
            v=parent[v];
        }

        int sum=0;

        while(u){

            sum+=value[u];
            u=parent[u];
        }

        printf("%d\n",sum);
    }

    return 0;
}
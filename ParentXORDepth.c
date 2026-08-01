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

        int ans=0;

        while(u){

            ans^=value[u];
            u=parent[u];
        }

        printf("%d\n",ans);
    }

    return 0;
}
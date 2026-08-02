#include <stdio.h>

#define MAXN 1005

int parent[MAXN];
int value[MAXN];

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

        int sign=1;
        int ans=0;

        while(u){

            ans += sign * value[u];
            sign *= -1;
            u=parent[u];
        }

        printf("%d\n",ans);
    }

    return 0;
}
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

        int u;
        scanf("%d",&u);

        int maxVal=value[u], minVal=value[u];
        int maxDepth=depth[u], minDepth=depth[u];

        int cur=u;

        while(cur){

            if(value[cur]>maxVal){
                maxVal=value[cur];
                maxDepth=depth[cur];
            }

            if(value[cur]<minVal){
                minVal=value[cur];
                minDepth=depth[cur];
            }

            cur=parent[cur];
        }

        printf("%d\n", maxVal*maxDepth - minVal*minDepth);
    }

    return 0;
}
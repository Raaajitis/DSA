#include <stdio.h>

#define MAXN 205

int parent[MAXN];
int value[MAXN];
int graph[MAXN][MAXN];
int visited[MAXN];

int dfs(int u,int target,int xr){

    if(u==target)
        return xr^value[u];

    visited[u]=1;

    for(int v=1;v<MAXN;v++){

        if(graph[u][v] && !visited[v]){

            int ans=dfs(v,target,xr^value[u]);

            if(ans!=-1)
                return ans;
        }
    }

    return -1;
}

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    while(q--){

        int type;

        scanf("%d",&type);

        if(type==1){

            int u,v;

            scanf("%d%d",&u,&v);

            graph[u][v]=graph[v][u]=1;

        }else if(type==2){

            int u,x;

            scanf("%d%d",&u,&x);

            value[u]=x;

        }else{

            int u,v;

            scanf("%d%d",&u,&v);

            for(int i=0;i<MAXN;i++)
                visited[i]=0;

            printf("%d\n",dfs(u,v,0));
        }
    }

    return 0;
}
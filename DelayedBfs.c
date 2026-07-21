#include <stdio.h>
#include <limits.h>

#define MAX 105
#define INF 1000000000

int g[MAX][MAX],deg[MAX];

int main(){

    int n,m;

    scanf("%d%d",&n,&m);

    int t[MAX];

    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);

    for(int i=0;i<m;i++){

        int u,v;

        scanf("%d%d",&u,&v);

        g[u][deg[u]++]=v;
        g[v][deg[v]++]=u;
    }

    int dist[MAX];
    int vis[MAX]={0};

    for(int i=1;i<=n;i++)
        dist[i]=INF;

    dist[1]=0;

    while(1){

        int u=-1;

        for(int i=1;i<=n;i++)
            if(!vis[i] && (u==-1 || dist[i]<dist[u]))
                u=i;

        if(u==-1) break;

        vis[u]=1;

        for(int i=0;i<deg[u];i++){

            int v=g[u][i];

            int arrive=dist[u]+1;

            if(arrive<t[v])
                arrive=t[v];

            if(arrive<dist[v])
                dist[v]=arrive;
        }
    }

    if(dist[n]==INF)
        printf("-1");
    else
        printf("%d\n",dist[n]);

    return 0;
}
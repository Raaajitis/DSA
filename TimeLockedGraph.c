#include <stdio.h>
#include <limits.h>

#define MAXN 105
#define INF 1000000000

int cost[MAXN][MAXN];

int main() {

    int n,m;

    scanf("%d%d",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cost[i][j]=-1;

    while(m--){

        int u,v,t;

        scanf("%d%d%d",&u,&v,&t);

        cost[u][v]=cost[v][u]=t;
    }

    int dist[MAXN];
    int vis[MAXN]={0};

    for(int i=1;i<=n;i++)
        dist[i]=INF;

    dist[1]=0;

    for(int k=1;k<=n;k++){

        int u=-1;

        for(int i=1;i<=n;i++)
            if(!vis[i]&&(u==-1||dist[i]<dist[u]))
                u=i;

        if(u==-1) break;

        vis[u]=1;

        for(int v=1;v<=n;v++){

            if(cost[u][v]==-1)
                continue;

            int arrive=dist[u];

            if(arrive<cost[u][v])
                arrive=cost[u][v];

            arrive++;

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
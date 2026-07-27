#include <stdio.h>

#define MAXN 1005

int parent[MAXN];
char color[MAXN];
int head[MAXN],to[2*MAXN],next[2*MAXN],idx=0;

void addEdge(int u,int v){
    to[idx]=v;
    next[idx]=head[u];
    head[u]=idx++;
}

void flip(int u){

    color[u]=(color[u]=='R')?'B':'R';

    for(int e=head[u];e!=-1;e=next[e])
        flip(to[e]);
}

int dfs(int u){

    int best=1;

    for(int e=head[u];e!=-1;e=next[e]){

        int v=to[e];

        if(color[v]!=color[u]){

            int len=1+dfs(v);

            if(len>best)
                best=len;
        }
    }

    return best;
}

int main(){

    int n,q;

    scanf("%d",&n);

    for(int i=0;i<=n;i++)
        head[i]=-1;

    parent[1]=0;

    for(int i=2;i<=n;i++){

        scanf("%d",&parent[i]);
        addEdge(parent[i],i);
    }

    for(int i=1;i<=n;i++)
        scanf(" %c",&color[i]);

    scanf("%d",&q);

    while(q--){

        int type,u;

        scanf("%d%d",&type,&u);

        if(type==1){

            flip(u);

        }else{

            printf("%d\n",dfs(u));
        }
    }

    return 0;
}
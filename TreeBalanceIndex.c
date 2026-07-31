#include <stdio.h>

#define MAXN 1005

int value[MAXN];
int head[MAXN],to[MAXN],next[MAXN],idx=0;
int sub[MAXN];
int total=0;

void addEdge(int u,int v){

    to[idx]=v;
    next[idx]=head[u];
    head[u]=idx++;
}

void dfs(int u){

    sub[u]=value[u];

    for(int e=head[u];e!=-1;e=next[e]){

        dfs(to[e]);

        sub[u]+=sub[to[e]];
    }
}

int main(){

    int n;

    scanf("%d",&n);

    for(int i=0;i<=n;i++)
        head[i]=-1;

    for(int i=1;i<=n;i++){

        scanf("%d",&value[i]);
        total+=value[i];
    }

    for(int i=2;i<=n;i++){

        int p;
        scanf("%d",&p);

        addEdge(p,i);
    }

    dfs(1);

    int bestNode=1;
    int bestValue=2*sub[1]-total;

    for(int i=2;i<=n;i++){

        int bal=2*sub[i]-total;

        if(bal>bestValue){

            bestValue=bal;
            bestNode=i;
        }
    }

    printf("%d\n",bestNode);

    return 0;
}
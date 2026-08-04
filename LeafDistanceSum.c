#include<stdio.h>

#define MAX 1005

int head[MAX],to[MAX],next[MAX],idx=0;
int ans=0;

void addEdge(int u,int v){

    to[idx]=v;
    next[idx]=head[u];
    head[u]=idx++;
}

void dfs(int u,int depth){

    if(head[u]==-1){

        ans+=depth;
        return;
    }

    for(int e=head[u];e!=-1;e=next[e])
        dfs(to[e],depth+1);
}

int main(){

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        head[i]=-1;

    for(int i=2;i<=n;i++){

        int p;

        scanf("%d",&p);

        addEdge(p,i);
    }

    dfs(1,0);

    printf("%d\n",ans);

    return 0;
}
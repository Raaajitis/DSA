#include <stdio.h>

#define N 3

int a[N][N]={
    {1,0,1},
    {1,1,0},
    {0,1,1}
};

int vis[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int x,int y){

    if(x<0||x>=N||y<0||y>=N)
        return;

    if(vis[x][y]||a[x][y]==0)
        return;

    vis[x][y]=1;

    for(int k=0;k<4;k++)
        dfs(x+dx[k],y+dy[k]);
}

int main(){

    int islands=0;

    for(int i=0;i<N;i++){

        for(int j=0;j<N;j++){

            if(a[i][j]&&!vis[i][j]){

                dfs(i,j);
                islands++;
            }
        }
    }

    printf("%d\n",islands);

    return 0;
}
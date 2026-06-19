#include <stdio.h>

#define N 3
#define M 3

char grid[N][M] = {
    {'S','B','B'},
    {'#','#','B'},
    {'.','.','E'}
};

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x,int y){

    if(grid[x][y]=='E')
        return 1;

    char temp = grid[x][y];

    if(grid[x][y]=='B')
        grid[x][y]='.';

    grid[x][y]='#';

    for(int k=0;k<4;k++){

        int nx=x+dx[k];
        int ny=y+dy[k];

        if(nx>=0&&ny>=0&&
           nx<N&&ny<M&&
           grid[nx][ny]!='#'){

            if(dfs(nx,ny))
                return 1;
        }
    }

    grid[x][y]=temp;

    return 0;
}

int main(){

    if(dfs(0,0))
        printf("Reachable\n");
    else
        printf("Not Reachable\n");

    return 0;
}
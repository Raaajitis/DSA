#include <stdio.h>

#define N 3

char maze[N][N] = {
    {'S','.','.'},
    {'.','#','.'},
    {'.','.','E'}
};

int count = 0;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x,int y) {

    if(maze[x][y] == 'E') {

        count++;
        return;
    }

    char temp = maze[x][y];

    maze[x][y] = '#';

    for(int k=0;k<4;k++) {

        int nx = x + dx[k];
        int ny = y + dy[k];

        if(nx>=0 && ny>=0 &&
           nx<N && ny<N &&
           maze[nx][ny] != '#') {

            dfs(nx,ny);
        }
    }

    maze[x][y] = temp;
}

int main() {

    dfs(0,0);

    printf("Total Paths = %d\n",
           count);

    return 0;
}
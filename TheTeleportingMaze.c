#include <stdio.h>

#define N 3

typedef struct {
    int x,y,dist;
} Node;

int main() {

    char grid[N][N] = {
        {'S','.','A'},
        {'#','#','.'},
        {'A','.','E'}
    };

    int visited[N][N] = {0};

    int ax1=-1, ay1=-1;
    int ax2=-1, ay2=-1;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {

            if(grid[i][j]=='A') {

                if(ax1==-1) {
                    ax1=i;
                    ay1=j;
                }
                else {
                    ax2=i;
                    ay2=j;
                }
            }
        }
    }

    Node q[100];

    int front=0,rear=0;

    q[rear++] = (Node){0,0,0};
    visited[0][0]=1;

    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};

    while(front<rear) {

        Node cur=q[front++];

        if(grid[cur.x][cur.y]=='E') {

            printf("Shortest Path = %d\n",
                   cur.dist);
            return 0;
        }

        for(int k=0;k<4;k++) {

            int nx=cur.x+dx[k];
            int ny=cur.y+dy[k];

            if(nx>=0 && ny>=0 &&
               nx<N && ny<N &&
               !visited[nx][ny] &&
               grid[nx][ny]!='#') {

                visited[nx][ny]=1;

                if(grid[nx][ny]=='A') {

                    if(nx==ax1 && ny==ay1) {
                        nx=ax2;
                        ny=ay2;
                    }
                    else {
                        nx=ax1;
                        ny=ay1;
                    }
                }

                q[rear++] =
                (Node){nx,ny,cur.dist+1};
            }
        }
    }

    printf("No Path\n");

    return 0;
}
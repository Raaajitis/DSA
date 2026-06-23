#include <stdio.h>

int main() {

    char moves[] = "RRDLLURR";

    int visited[201][201][4] = {0};

    int x = 100, y = 100;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    char dir[] = {'U','D','L','R'};

    int count = 0;

    for(int i=0;moves[i];i++){

        int d;

        if(moves[i]=='U') d=0;
        else if(moves[i]=='D') d=1;
        else if(moves[i]=='L') d=2;
        else d=3;

        x += dx[d];
        y += dy[d];

        if(visited[x][y][d]){

            printf("Stopped after %d moves\n",count);
            return 0;
        }

        visited[x][y][d]=1;
        count++;
    }

    printf("Completed all %d moves\n",count);

    return 0;
}
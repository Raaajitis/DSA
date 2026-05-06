#include <stdio.h>

#define N 2

int isValid(int x, int y) {
    return x>=0 && y>=0 && x<N && y<N;
}

int shortestPath(int grid[N][N]) {

    if (grid[0][0] == 1) return -1;

    int dir[8][2] = {
        {1,0},{-1,0},{0,1},{0,-1},
        {1,1},{-1,-1},{1,-1},{-1,1}
    };

    int queue[N*N][3];
    int front = 0, rear = 0;

    queue[rear][0] = 0;
    queue[rear][1] = 0;
    queue[rear][2] = 1;
    rear++;

    grid[0][0] = 1
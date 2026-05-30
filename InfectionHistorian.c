#include <stdio.h>

#define N 3

int main() {

    int graph[N][N] = {
        {0,1,0},
        {1,0,1},
        {0,1,0}
    };

    int time[N] = {0,1,2};

    int valid = 1;

    for(int i=0;i<N;i++) {

        if(time[i] == 0)
            continue;

        int found = 0;

        for(int j=0;j<N;j++) {

            if(graph[i][j] &&
               time[j] == time[i]-1) {

                found = 1;
                break;
            }
        }

        if(!found) {
            valid = 0;
            break;
        }
    }

    if(valid)
        printf("Timeline Possible\n");
    else
        printf("Timeline Impossible\n");

    return 0;
}
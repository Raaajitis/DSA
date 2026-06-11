#include <stdio.h>

#define N 4

int main() {

    int graph[N][N] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };

    int color[N] = {0,1,1,0};

    int rounds = 0;

    while(1) {

        int next[N];
        int changed = 0;

        for(int i=0;i<N;i++)
            next[i] = color[i];

        for(int i=0;i<N;i++) {

            if(color[i] == 0) {

                int black = 0;

                for(int j=0;j<N;j++) {

                    if(graph[i][j] &&
                       color[j] == 1)
                        black++;
                }

                if(black >= 2) {

                    next[i] = 1;
                    changed = 1;
                }
            }
        }

        if(!changed)
            break;

        for(int i=0;i<N;i++)
            color[i] = next[i];

        rounds++;
    }

    printf("Rounds = %d\n", rounds);

    printf("Final Colors:\n");

    for(int i=0;i<N;i++)
        printf("%d ", color[i]);

    return 0;
}
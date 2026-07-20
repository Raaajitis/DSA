#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int signal[MAX];
int visited[MAX];

int queue[MAX];

int main() {

    int n,m,k;

    scanf("%d%d%d",&n,&m,&k);

    for(int i=0;i<m;i++){

        int u,v;

        scanf("%d%d",&u,&v);

        graph[u][v]=1;
        graph[v][u]=1;
    }

    int front=0,rear=0;

    queue[rear++]=1;

    signal[1]=k;
    visited[1]=1;

    while(front<rear){

        int u=queue[front++];

        for(int v=1;v<=n;v++){

            if(graph[u][v] && !visited[v]){

                signal[v]=signal[u]/2;

                visited[v]=1;

                queue[rear++]=v;
            }
        }
    }

    int count=0;
    int mx=0;

    for(int i=1;i<=n;i++){

        if(visited[i]){

            count++;

            if(signal[i]>mx)
                mx=signal[i];
        }
    }

    printf("Nodes = %d\n",count);
    printf("Maximum Signal = %d\n",mx);

    return 0;
}
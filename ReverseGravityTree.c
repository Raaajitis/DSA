#include <stdio.h>

#define MAX 100

int parent[MAX];
int weight[MAX];
int alive[MAX];

int main() {

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d",&weight[i]);

    parent[1]=0;

    for(int i=2;i<=n;i++)
        scanf("%d",&parent[i]);

    for(int i=1;i<=n;i++)
        alive[i]=1;

    int seconds=0;

    while(1){

        int aliveCount=0;

        for(int i=1;i<=n;i++)
            if(alive[i])
                aliveCount++;

        if(aliveCount==1)
            break;

        int add[MAX]={0};
        int remove[MAX]={0};

        for(int i=1;i<=n;i++){

            if(!alive[i])
                continue;

            int child=0;

            for(int j=1;j<=n;j++)
                if(alive[j] && parent[j]==i)
                    child++;

            if(child==0){

                if(parent[i]!=0)
                    add[parent[i]]++;

                weight[i]--;

                if(weight[i]<=0)
                    remove[i]=1;
            }
        }

        for(int i=1;i<=n;i++)
            weight[i]+=add[i];

        for(int i=1;i<=n;i++)
            if(remove[i])
                alive[i]=0;

        seconds++;
    }

    for(int i=1;i<=n;i++){

        if(alive[i]){

            printf("Remaining Node : %d\n",i);
            printf("Weight : %d\n",weight[i]);
        }
    }

    printf("Seconds : %d\n",seconds);

    return 0;
}
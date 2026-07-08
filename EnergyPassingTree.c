#include <stdio.h>

#define MAX 100

int parent[MAX];
int energy[MAX];
int alive[MAX];

int main(){

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d",&energy[i]);

    parent[1]=0;

    for(int i=2;i<=n;i++)
        scanf("%d",&parent[i]);

    for(int i=1;i<=n;i++)
        alive[i]=1;

    while(1){

        int aliveCount=0;

        for(int i=1;i<=n;i++)
            if(alive[i])
                aliveCount++;

        if(aliveCount==1)
            break;

        int add[MAX]={0};

        for(int i=1;i<=n;i++){

            if(!alive[i])
                continue;

            int child=0;

            for(int j=2;j<=n;j++)
                if(alive[j] && parent[j]==i)
                    child++;

            if(child==0 && parent[i]!=0){

                int give=energy[i]/2;

                add[parent[i]]+=give;
                energy[i]-=give;

                if(energy[i]==0)
                    alive[i]=0;
            }
        }

        for(int i=1;i<=n;i++)
            energy[i]+=add[i];
    }

    printf("%d\n",energy[1]);

    return 0;
}
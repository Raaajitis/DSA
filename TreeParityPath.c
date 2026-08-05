#include <stdio.h>

#define MAX 1005

int parent[MAX];
int value[MAX];

int main(){

    int n,q;

    scanf("%d%d",&n,&q);

    for(int i=1;i<=n;i++)
        scanf("%d",&value[i]);

    parent[1]=0;

    for(int i=2;i<=n;i++)
        scanf("%d",&parent[i]);

    while(q--){

        int u;
        scanf("%d",&u);

        int even=0,odd=0;

        while(u){

            if(value[u]%2==0)
                even++;
            else
                odd++;

            u=parent[u];
        }

        if(even>odd)
            printf("EVEN\n");
        else
            printf("ODD\n");
    }

    return 0;
}
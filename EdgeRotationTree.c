#include<stdio.h>

#define MAXN 1005

int parent[MAXN];
int weight[MAXN];

int main(){

    int n;

    scanf("%d",&n);

    parent[1]=0;

    for(int i=2;i<=n;i++)
        scanf("%d",&parent[i]);

    for(int i=2;i<=n;i++)
        scanf("%d",&weight[i]);

    int q;

    scanf("%d",&q);

    while(q--){

        int type,u;

        scanf("%d%d",&type,&u);

        if(type==1){

            int nodes[MAXN];
            int w[MAXN];
            int len=0;

            int cur=u;

            while(cur!=1){

                nodes[len]=cur;
                w[len]=weight[cur];

                cur=parent[cur];
                len++;
            }

            if(len>1){

                int last=w[len-1];

                for(int i=len-1;i>=1;i--)
                    weight[nodes[i]]=w[i-1];

                weight[nodes[0]]=last;
            }
        }

        else{

            int sum=0;

            while(u!=1){

                sum+=weight[u];
                u=parent[u];
            }

            printf("%d\n",sum);
        }
    }

    return 0;
}
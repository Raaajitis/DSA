#include <stdio.h>

#define MAXN 1005

int parent[MAXN];
int value[MAXN];

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

        int val[1005];
        int cnt[1005];
        int sz=0;

        while(u){

            int found=-1;

            for(int i=0;i<sz;i++){

                if(val[i]==value[u]){
                    found=i;
                    break;
                }
            }

            if(found==-1){

                val[sz]=value[u];
                cnt[sz]=1;
                sz++;

            }else{

                cnt[found]++;
            }

            u=parent[u];
        }

        int bestVal=val[0];
        int bestCnt=cnt[0];

        for(int i=1;i<sz;i++){

            if(cnt[i]>bestCnt ||
              (cnt[i]==bestCnt && val[i]<bestVal)){

                bestCnt=cnt[i];
                bestVal=val[i];
            }
        }

        printf("%d\n",bestVal);
    }

    return 0;
}
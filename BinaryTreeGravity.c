#include <stdio.h>

#define MAX 100

int left[MAX];
int right[MAX];
int alive[MAX];

int main(){

    int n;

    scanf("%d",&n);

    for(int i=1;i<=n;i++){

        scanf("%d%d",&left[i],&right[i]);

        alive[i]=1;
    }

    while(1){

        int remove[MAX]={0};

        int changed=0;

        for(int i=1;i<=n;i++){

            if(!alive[i])
                continue;

            int cnt=0;

            if(left[i]!=-1&&alive[left[i]]) cnt++;
            if(right[i]!=-1&&alive[right[i]]) cnt++;

            if(cnt==1){

                remove[i]=1;
                changed=1;
            }
        }

        if(!changed)
            break;

        for(int i=1;i<=n;i++)
            if(remove[i])
                alive[i]=0;
    }

    int ans=0;

    for(int i=1;i<=n;i++)
        if(alive[i])
            ans++;

    printf("%d\n",ans);

    return 0;
}
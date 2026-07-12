#include <stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[100];
    int vis[100]={0};

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int cur=0;
    int step=1;
    int dir=1;

    int count=0,sum=0;

    while(!vis[cur]){

        vis[cur]=1;
        count++;
        sum+=a[cur];

        cur=(cur+dir*step)%n;

        if(cur<0)
            cur+=n;

        dir*=-1;
        step++;
    }

    printf("Visited = %d\n",count);
    printf("Sum = %d\n",sum);

    return 0;
}
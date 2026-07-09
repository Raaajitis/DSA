#include<stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[100],vis[100]={0};

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int dir=1;

    int cur=0;

    int count=0,sum=0;

    while(cur>=0 && cur<n && !vis[cur]){

        vis[cur]=1;

        count++;
        sum+=a[cur];

        int next=cur+dir*a[cur];

        if(next<0 || next>=n){

            dir*=-1;

            next=cur+dir*a[cur];

            if(next<0 || next>=n)
                break;
        }

        cur=next;
    }

    printf("Visited = %d\n",count);
    printf("Sum = %d\n",sum);

    return 0;
}
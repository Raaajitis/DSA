#include<stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[100];
    int vis[100]={0};

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int idx=0;
    int jump=1;

    int count=0,sum=0;

    while(!vis[idx]){

        vis[idx]=1;

        count++;
        sum+=a[idx];

        idx=(idx+jump*a[idx])%n;

        jump++;
    }

    printf("Visited = %d\n",count);
    printf("Sum = %d\n",sum);

    return 0;
}
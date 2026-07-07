#include <stdio.h>

int main(){

    int n;

    scanf("%d",&n);

    int a[100];
    int vis[100]={0};

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int cur=0;

    int count=0;
    int sum=0;

    while(!vis[cur]){

        vis[cur]=1;

        count++;

        sum+=a[cur];

        cur=(cur+a[cur])%n;
    }

    printf("Visited = %d\n",count);

    printf("Sum = %d\n",sum);

    return 0;
}
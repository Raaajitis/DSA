#include <stdio.h>

#define MAX 100

int a[MAX];
int vis[MAX];
int n;
int sum;

void dfs(int i){

    if(i<0 || i>=n || vis[i])
        return;

    vis[i]=1;
    sum+=a[i];

    if(i>0 && a[i]>a[i-1])
        dfs(i-1);

    if(i<n-1 && a[i]>a[i+1])
        dfs(i+1);
}

int main(){

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int ans=0;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++)
            vis[j]=0;

        sum=0;

        dfs(i);

        if(sum>ans)
            ans=sum;
    }

    printf("%d\n",ans);

    return 0;
}
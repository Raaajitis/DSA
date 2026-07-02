#include <stdio.h>

#define MAX 100

int a[MAX];
int vis[MAX];
int n;

void dfs(int i){

    if(i<0 || i>=n || vis[i])
        return;

    vis[i]=1;

    if(i>0 && a[i]>a[i-1])
        dfs(i-1);

    if(i<n-1 && a[i]>a[i+1])
        dfs(i+1);
}

int main(){

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(int start=0;start<n;start++){

        for(int i=0;i<n;i++)
            vis[i]=0;

        dfs(start);

        int ok=1;

        for(int i=0;i<n;i++)
            if(!vis[i])
                ok=0;

        if(ok){

            printf("%d\n",start);
            return 0;
        }
    }

    printf("-1");

    return 0;
}
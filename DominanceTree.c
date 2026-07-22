#include<stdio.h>

int a[105];
int ans=0;

void solve(int l,int r,int depth){

    if(l>r)
        return;

    int mx=l;

    for(int i=l+1;i<=r;i++)
        if(a[i]>a[mx])
            mx=i;

    ans+=a[mx]*depth;

    solve(l,mx-1,depth+1);
    solve(mx+1,r,depth+1);
}

int main(){

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    solve(0,n-1,1);

    printf("%d",ans);

    return 0;
}
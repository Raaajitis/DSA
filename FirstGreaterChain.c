#include<stdio.h>

#define MAX 100005

int a[MAX];
int nextGreater[MAX];
int stack[MAX];
int dp[MAX];

int main(){

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int top=-1;

    for(int i=n-1;i>=0;i--){

        while(top!=-1 && a[stack[top]]<a[i])
            top--;

        if(top==-1)
            nextGreater[i]=-1;
        else
            nextGreater[i]=stack[top];

        stack[++top]=i;
    }

    int ans=1;

    for(int i=n-1;i>=0;i--){

        if(nextGreater[i]==-1)
            dp[i]=1;
        else
            dp[i]=1+dp[nextGreater[i]];

        if(dp[i]>ans)
            ans=dp[i];
    }

    printf("%d\n",ans);

    return 0;
}
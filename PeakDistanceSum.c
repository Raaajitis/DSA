#include <stdio.h>

#define MAX 100005

int a[MAX], left[MAX], right[MAX], st[MAX];

int main() {

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int top=-1;

    for(int i=0;i<n;i++){

        while(top!=-1 && a[st[top]]<a[i])
            top--;

        left[i]=(top==-1)?-1:st[top];

        st[++top]=i;
    }

    top=-1;

    for(int i=n-1;i>=0;i--){

        while(top!=-1 && a[st[top]]<a[i])
            top--;

        right[i]=(top==-1)?-1:st[top];

        st[++top]=i;
    }

    long long ans=0;

    for(int i=0;i<n;i++)
        if(left[i]!=-1 && right[i]!=-1)
            ans+=right[i]-left[i];

    printf("%lld",ans);

    return 0;
}
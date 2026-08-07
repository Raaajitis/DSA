#include <stdio.h>

#define MAX 100005

int a[MAX];
int leftGreater[MAX], rightGreater[MAX];
int st[MAX];

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int top=-1;

    // Nearest Greater Left
    for(int i=0;i<n;i++){
        while(top!=-1 && a[st[top]]<a[i])
            top--;

        leftGreater[i]=(top==-1)?-1:st[top];
        st[++top]=i;
    }

    top=-1;

    // Nearest Greater Right
    for(int i=n-1;i>=0;i--){
        while(top!=-1 && a[st[top]]<a[i])
            top--;

        rightGreater[i]=(top==-1)?-1:st[top];
        st[++top]=i;
    }

    long long ans=0;

    for(int i=0;i<n;i++){
        if(leftGreater[i]!=-1 && rightGreater[i]!=-1){
            ans += (rightGreater[i]-leftGreater[i]-1);
        }
    }

    printf("%lld\n",ans);

    return 0;
}
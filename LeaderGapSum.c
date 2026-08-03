#include <stdio.h>

#define MAX 100005

int a[MAX];
int leaderIndex[MAX];

int main() {

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int count=0;
    int mx=-2147483648;

    for(int i=n-1;i>=0;i--){

        if(a[i]>mx){

            mx=a[i];
            leaderIndex[count++]=i;
        }
    }

    long long ans=0;

    for(int i=count-1;i>0;i--)
        ans+=leaderIndex[i]-leaderIndex[i-1];

    printf("%lld\n",ans);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 1005

int a[MAX], b[MAX];

int main() {

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    long long ans=0;

    while(n>1){

        int mx=0;

        for(int i=0;i<n-1;i++){

            b[i]=abs(a[i]-a[i+1]);

            if(b[i]>mx)
                mx=b[i];
        }

        ans+=mx;

        for(int i=0;i<n-1;i++)
            a[i]=b[i];

        n--;
    }

    printf("%lld\n",ans);

    return 0;
}
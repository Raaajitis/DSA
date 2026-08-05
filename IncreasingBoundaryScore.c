#include <stdio.h>

#define MAX 1005

int a[MAX];

int main() {

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    long long ans=0;

    for(int l=0;l<n;l++){

        for(int r=l+1;r<n;r++){

            if(a[l]<a[r])
                ans+=a[r]-a[l];
        }
    }

    printf("%lld\n",ans);

    return 0;
}
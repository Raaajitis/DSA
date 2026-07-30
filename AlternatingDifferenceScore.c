#include <stdio.h>

#define MAXN 1005

int main() {

    int n;
    scanf("%d",&n);

    int a[MAXN];

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    long long ans=0;

    for(int l=0;l<n;l++){

        int mx1=-1000000000;
        int mx2=-1000000000;

        for(int r=l;r<n;r++){

            if(a[r]>mx1){
                mx2=mx1;
                mx1=a[r];
            }
            else if(a[r]>mx2){
                mx2=a[r];
            }

            if(r-l+1>=2)
                ans+=mx1-mx2;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
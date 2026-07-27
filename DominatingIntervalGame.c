#include <stdio.h>

#define MAXN 1005

int a[MAXN];

int main() {

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int ans=0;

    for(int l=0;l<n;l++){

        int mx=a[l];
        int pos=l;

        for(int r=l;r<n;r++){

            if(a[r]>mx){
                mx=a[r];
                pos=r;
            }

            int len=r-l+1;

            if(len%2==1){

                int mid=(l+r)/2;

                if(pos==mid)
                    ans++;
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}
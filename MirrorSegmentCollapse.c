#include <stdio.h>

int main() {

    int a[100];
    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int found=0;

        for(int len=2;len<=n && !found;len+=2){

            for(int l=0;l+len<=n && !found;l++){

                int ok=1;

                for(int k=0;k<len/2;k++){

                    if(a[l+k]!=a[l+len/2+k]){
                        ok=0;
                        break;
                    }
                }

                if(ok){

                    int sum=0;

                    for(int k=l;k<l+len;k++)
                        sum+=a[k];

                    a[l]=sum;

                    int idx=l+1;

                    for(int k=l+len;k<n;k++)
                        a[idx++]=a[k];

                    n-=len-1;
                    found=1;
                }
            }
        }

        if(!found)
            break;
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
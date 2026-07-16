#include <stdio.h>

int main() {

    int a[100], n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int sum=0;
        int pos=-1;

        for(int i=0;i<n;i++){

            sum+=a[i];

            if(sum%2==0){
                pos=i;
                break;
            }
        }

        if(pos==-1)
            break;

        a[0]=sum/2;

        int idx=1;

        for(int i=pos+1;i<n;i++)
            a[idx++]=a[i];

        n=idx;
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
#include<stdio.h>

int main(){

    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int found=0;

        for(int i=0;i<n-2;i++){

            int d1=a[i]-a[i+1];
            if(d1<0) d1=-d1;

            int d2=a[i+1]-a[i+2];
            if(d2<0) d2=-d2;

            if(d1==d2){

                a[i]=a[i]+a[i+1]+a[i+2];

                for(int j=i+1;j<n-2;j++)
                    a[j]=a[j+2];

                n-=2;
                found=1;
                break;
            }
        }

        if(!found)
            break;
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
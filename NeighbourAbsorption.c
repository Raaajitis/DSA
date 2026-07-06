#include <stdio.h>

#define MAX 100

int main() {

    int a[MAX], n;

    scanf("%d", &n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int found=0;

        for(int i=1;i<n-1;i++){

            if(a[i]>a[i-1] && a[i]>a[i+1]){

                a[i]=a[i-1]+a[i]+a[i+1];

                for(int j=i-1;j<n-2;j++)
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
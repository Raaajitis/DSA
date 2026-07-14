#include<stdio.h>
#include<stdlib.h>

int main(){

    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int found=0;

        for(int i=0;i<n-1;i++){

            if(abs(a[i]-a[i+1])<=2){

                a[i]=a[i]^a[i+1];

                for(int j=i+1;j<n-1;j++)
                    a[j]=a[j+1];

                n--;
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
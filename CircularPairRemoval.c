#include<stdio.h>

int main(){

    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(n>1){

        int found=0;

        for(int i=0;i<n;i++){

            int j=(i+1)%n;

            if((a[i]+a[j])%2==0){

                if(j==0){

                    for(int k=0;k<n-2;k++)
                        a[k]=a[k+1];

                    n-=2;
                }
                else{

                    for(int k=j;k<n-1;k++)
                        a[k]=a[k+1];

                    for(int k=i;k<n-2;k++)
                        a[k]=a[k+1];

                    n-=2;
                }

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
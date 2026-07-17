#include<stdio.h>

int main(){

    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int found=0;

        for(int i=1;i<n-1;i++){

            int leftSmall=0,rightGreater=0;

            for(int j=0;j<i;j++)
                if(a[j]<a[i]){
                    leftSmall=1;
                    break;
                }

            for(int j=i+1;j<n;j++)
                if(a[j]>a[i]){
                    rightGreater=1;
                    break;
                }

            if(leftSmall && rightGreater){

                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;

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
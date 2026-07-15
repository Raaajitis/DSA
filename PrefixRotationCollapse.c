#include<stdio.h>

int main(){

    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int pos=-1;

        for(int i=1;i<n;i++){

            if(a[i]==a[0]){
                pos=i;
                break;
            }
        }

        if(pos==-1)
            break;

        int first=a[0];

        for(int i=0;i<pos;i++)
            a[i]=a[i+1];

        a[pos-1]=first;

        for(int i=pos;i<n-1;i++)
            a[i]=a[i+1];

        n--;
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
#include <stdio.h>

int main() {

    int a[] = {5,2,4};
    int n = 3;

    while(1){

        int delta[100]={0};
        int changed=0;

        for(int i=0;i<n;i++){

            if(i>0 && a[i]>a[i-1] && a[i]>0){
                delta[i]--;
                delta[i-1]++;
                changed=1;
            }

            if(i<n-1 && a[i]>a[i+1] && a[i]>0){
                delta[i]--;
                delta[i+1]++;
                changed=1;
            }
        }

        if(!changed)
            break;

        for(int i=0;i<n;i++)
            a[i]+=delta[i];
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
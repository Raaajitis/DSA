#include <stdio.h>

int main() {

    int arr[] = {3,8,1,6,2};
    int n = 5;

    int changed;

    do {

        changed = 0;
        int next[100];

        for(int i=0;i<n;i++)
            next[i]=arr[i];

        for(int i=0;i<n;i++) {

            int best=i;

            if(i>0 && arr[i-1]>arr[best])
                best=i-1;

            if(i<n-1 && arr[i+1]>arr[best])
                best=i+1;

            if(best!=i){

                next[best]=arr[i];
                next[i]=arr[best];
                changed=1;
            }
        }

        for(int i=0;i<n;i++)
            arr[i]=next[i];

    }while(changed);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
#include <stdio.h>

int main() {

    int arr[] = {4,1,6,2,5};
    int n = 5;

    int changed;

    do {

        changed = 0;
        int next[100];

        for(int i=0;i<n;i++)
            next[i]=arr[i];

        for(int i=0;i<n;i++) {

            int nearest=-1,dist=1000;

            for(int j=0;j<n;j++) {

                if(arr[j]>arr[i]) {

                    int d=abs(i-j);

                    if(d<dist){
                        dist=d;
                        nearest=j;
                    }
                }
            }

            if(nearest!=-1){

                if(nearest<i){
                    int t=next[i];
                    next[i]=next[i-1];
                    next[i-1]=t;
                }
                else if(nearest>i){
                    int t=next[i];
                    next[i]=next[i+1];
                    next[i+1]=t;
                }

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
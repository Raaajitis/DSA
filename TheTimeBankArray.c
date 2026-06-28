#include <stdio.h>

int main() {

    int a[] = {3,1,2};
    int n = 3;

    int death[100] = {0};
    int t = 0;

    while(1){

        int alive = 0;

        int give[100] = {0};

        for(int i=0;i<n;i++){

            if(a[i]>0)
                alive = 1;

            if(a[i]>=2){

                if(i>0 && a[i-1]<a[i])
                    give[i] = -1, give[i-1]++;

                else if(i<n-1 && a[i+1]<a[i])
                    give[i] = -1, give[i+1]++;
            }
        }

        if(!alive)
            break;

        for(int i=0;i<n;i++)
            a[i] += give[i];

        for(int i=0;i<n;i++){

            if(a[i]>0)
                a[i]--;

            if(a[i]==0 && death[i]==0)
                death[i]=t+1;
        }

        t++;
    }

    printf("Death Times:\n");

    for(int i=0;i<n;i++)
        printf("%d ",death[i]);

    return 0;
}
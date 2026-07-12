#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int operations=0;

    while(1){

        int found=0;

        for(int i=1;i<n-1;i++){

            if(a[i]<a[i-1] && a[i]<a[i+1]){

                a[i]+=abs(a[i-1]-a[i+1]);

                operations++;
                found=1;
                break;
            }
        }

        if(!found)
            break;
    }

    printf("Final Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\nOperations = %d\n",operations);

    return 0;
}
#include <stdio.h>

int main(){

    int n;
    int a[100];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    int removed=0;

    while(1){

        int found=0;

        for(int end=0;end<n;end++){

            int mx=a[0],idx=0;

            for(int i=1;i<=end;i++){

                if(a[i]>mx){
                    mx=a[i];
                    idx=i;
                }
            }

            int suffix=0;

            for(int i=end+1;i<n;i++)
                suffix+=a[i];

            if(mx==suffix){

                for(int i=idx;i<n-1;i++)
                    a[i]=a[i+1];

                n--;
                removed++;
                found=1;
                break;
            }
        }

        if(!found)
            break;
    }

    printf("Removals = %d\n",removed);

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    return 0;
}
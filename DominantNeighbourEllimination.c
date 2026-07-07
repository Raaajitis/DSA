#include <stdio.h>

int main() {

    int a[100];
    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    while(1){

        int found=0;

        for(int i=1;i<n-1;i++){

            if(a[i]>a[i-1] && a[i]>a[i+1]){

                int remove;

                if(a[i-1]<a[i+1])
                    remove=i-1;
                else
                    remove=i+1;

                a[i]-=a[remove];

                for(int j=remove;j<n-1;j++)
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
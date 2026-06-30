#include <stdio.h>

int main() {

    int arr[100]={4,1,3,2};
    int n=4;

    int changed;

    do{

        changed=0;

        for(int i=0;i<n;i++){

            if(i>0 && arr[i]>arr[i-1]){

                arr[i]+=arr[i-1];

                for(int j=i-1;j<n-1;j++)
                    arr[j]=arr[j+1];

                n--;
                changed=1;
                break;
            }

            if(i<n-1 && arr[i]>arr[i+1]){

                arr[i]+=arr[i+1];

                for(int j=i+1;j<n-1;j++)
                    arr[j]=arr[j+1];

                n--;
                changed=1;
                break;
            }
        }

    }while(changed);

    printf("Largest = %d\n",arr[0]);

    return 0;
}
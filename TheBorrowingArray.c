#include <stdio.h>

int main() {
    int arr[] = {1,3,2,5};
    int n = 4;

    int borrowed[100] = {0};

    for(int i=0;i<n;i++) {

        if(borrowed[i]) continue;

        if(arr[i] % 2 == 1) {

            if(i>0 && arr[i-1]>0) {
                arr[i]++;
                arr[i-1]--;
                borrowed[i]=1;
            }
            else if(i<n-1 && arr[i+1]>0) {
                arr[i]++;
                arr[i+1]--;
                borrowed[i]=1;
            }
        }
    }

    int sum=0;

    for(int i=0;i<n;i++)
        if(arr[i]%2==0)
            sum+=arr[i];

    printf("Maximum Even Sum = %d\n",sum);

    return 0;
}
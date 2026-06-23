#include <stdio.h>

#define MAX 100

int main() {

    int arr[] = {3,2,1};
    int n = 3;

    int swapped[MAX][MAX] = {0};

    int changed = 1;

    while(changed){

        changed = 0;

        for(int i=0;i<n-1;i++){

            if(arr[i] > arr[i+1]){

                int a = arr[i];
                int b = arr[i+1];

                if(swapped[a][b] || swapped[b][a]){

                    printf("IMPOSSIBLE\n");
                    return 0;
                }

                swapped[a][b] = swapped[b][a] = 1;

                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;

                changed = 1;
            }
        }
    }

    printf("Sorted:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
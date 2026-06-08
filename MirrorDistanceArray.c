#include <stdio.h>
#include <stdlib.h>

int main() {

    int arr[] = {5,1,3,5,1,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    int result[n];

    for(int i=0;i<n;i++) {

        int minDist = 1000000;

        for(int j=0;j<n;j++) {

            if(i != j && arr[i] == arr[j]) {

                int dist = abs(i-j);

                if(dist < minDist)
                    minDist = dist;
            }
        }

        if(minDist == 1000000)
            result[i] = -1;
        else
            result[i] = minDist;
    }

    printf("Output:\n");

    for(int i=0;i<n;i++)
        printf("%d ", result[i]);

    return 0;
}
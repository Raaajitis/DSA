#include <stdio.h>

int main() {

    int arr[] = {10,1,7};
    int n = 3;

    while(1) {

        int richest = 0;

        for(int i=1;i<n;i++)
            if(arr[i] > arr[richest])
                richest = i;

        int target = -1;

        if(richest > 0 &&
           (target == -1 ||
            arr[richest-1] < arr[target]))
            target = richest-1;

        if(richest < n-1 &&
           (target == -1 ||
            arr[richest+1] < arr[target]))
            target = richest+1;

        if(target == -1 ||
           arr[richest] <= arr[target] + 1)
            break;

        arr[richest]--;
        arr[target]++;
    }

    printf("Final Balances:\n");

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {

    int arr[] = {8,5,9,2};
    int n = 4;

    int prev[100];

    while (1) {

        memcpy(prev, arr, sizeof(int) * n);

        arr[0] = prev[0];

        int changed = 0;

        for (int i = 1; i < n; i++) {
            arr[i] = abs(prev[i] - prev[i-1]);

            if(arr[i] != prev[i])
                changed = 1;
        }

        if(!changed)
            break;
    }

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
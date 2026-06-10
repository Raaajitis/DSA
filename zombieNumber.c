#include <stdio.h>

int main() {

    int arr[] = {5,5,7,7,7};
    int n = 5;

    while(1) {

        int temp[n];
        int changed = 0;

        for(int i=0;i<n;i++) {

            int count = 0;

            for(int j=0;j<n;j++)
                if(arr[j] == arr[i])
                    count++;

            temp[i] = count;

            if(temp[i] != arr[i])
                changed = 1;
        }

        if(!changed)
            break;

        for(int i=0;i<n;i++)
            arr[i] = temp[i];
    }

    printf("Final Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
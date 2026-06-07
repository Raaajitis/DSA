#include <stdio.h>

int main() {

    int arr[100] = {2,2,4,8};
    int n = 4;

    int changed;

    do {
        changed = 0;

        for(int i=0;i<n-1;i++) {

            if(arr[i] == arr[i+1]) {

                arr[i] *= 2;

                for(int j=i+1;j<n-1;j++)
                    arr[j] = arr[j+1];

                n--;
                changed = 1;
                break;
            }
        }

    } while(changed);

    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    return 0;
}
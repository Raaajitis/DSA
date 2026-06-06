#include <stdio.h>

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    int arr[] = {1,2,2,3,3,3,2};
    int n = 7;

    int changed;
    int seconds = 0;

    do {

        changed = 0;

        int temp[n];

        for(int i = 0; i < n; i++) {

            int left  = (i > 0) ? arr[i-1] : arr[i];
            int self  = arr[i];
            int right = (i < n-1) ? arr[i+1] : arr[i];

            if(left == self || left == right)
                temp[i] = left;

            else if(self == right)
                temp[i] = self;

            else
                temp[i] = self;

            if(temp[i] != arr[i])
                changed = 1;
        }

        if(changed) {

            for(int i = 0; i < n; i++)
                arr[i] = temp[i];

            seconds++;
        }

    } while(changed);

    printf("Stable Array:\n");
    printArray(arr,n);

    printf("Seconds = %d\n",seconds);

    return 0;
}
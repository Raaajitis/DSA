#include <stdio.h>

int countWaves(int arr[], int n) {

    int count = 0;

    for (int i = 1; i < n - 1; i++) {

        int up1 = 0, down = 0, up2 = 0;

        while (i < n && arr[i] > arr[i-1]) {
            up1 = 1;
            i++;
        }

        while (i < n && arr[i] < arr[i-1]) {
            down = 1;
            i++;
        }

        while (i < n && arr[i] > arr[i-1]) {
            up2 = 1;
            i++;
        }

        if (up1 && down && up2)
            count++;
    }

    return count;
}

int main() {

    int arr[] = {1,3,5,2,4,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Temperature Waves: %d\n",
           countWaves(arr,n));

    return 0;
}
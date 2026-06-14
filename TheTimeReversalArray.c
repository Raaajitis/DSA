#include <stdio.h>

void reverse(int arr[], int end) {

    int l = 0;
    int r = end;

    while(l < r) {

        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        l++;
        r--;
    }
}

int main() {

    int arr[] = {1,2,3,4};
    int n = 4;

    printf("Removed Order:\n");

    while(n > 0) {

        int i = n - 1;

        reverse(arr, i);

        printf("%d ", arr[0]);

        for(int j=0;j<n-1;j++)
            arr[j] = arr[j+1];

        n--;
    }

    return 0;
}
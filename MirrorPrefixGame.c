#include <stdio.h>

void reverseNegate(int arr[], int k) {
    int l = 0, r = k;

    while (l < r) {
        int temp = arr[l];
        arr[l] = -arr[r];
        arr[r] = -temp;
        l++;
        r--;
    }

    if (l == r)
        arr[l] = -arr[l];
}

int isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] <= arr[i - 1])
            return 0;
    return 1;
}

int main() {

    int arr[] = {1,2,3,4};
    int n = 4;

    reverseNegate(arr,2);

    printf("Array:\n");

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n");

    if(isSorted(arr,n))
        printf("Increasing\n");
    else
        printf("Not Increasing\n");

    return 0;
}
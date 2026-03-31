#include <stdio.h>

int trap(int arr[], int n) {

    int leftMax[n], rightMax[n];

    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = (arr[i] > leftMax[i-1]) ? arr[i] : leftMax[i-1];

    rightMax[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
        rightMax[i] = (arr[i] > rightMax[i+1]) ? arr[i] : rightMax[i+1];

    int water = 0;

    for (int i = 0; i < n; i++) {
        int minHeight = (leftMax[i] < rightMax[i]) ? leftMax[i] : rightMax[i];
        water += minHeight - arr[i];
    }

    return water;
}

int main() {

    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Trapped Water: %d\n", trap(arr,n));

    return 0;
}
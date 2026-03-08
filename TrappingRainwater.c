#include <stdio.h>

int trapWater(int arr[], int n) {

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left <= right) {

        if (arr[left] <= arr[right]) {

            if (arr[left] > leftMax)
                leftMax = arr[left];
            else
                water += leftMax - arr[left];

            left++;
        }
        else {

            if (arr[right] > rightMax)
                rightMax = arr[right];
            else
                water += rightMax - arr[right];

            right--;
        }
    }

    return water;
}

int main() {

    int arr[] = {3, 0, 2, 0, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Trapped Water: %d\n", trapWater(arr, n));

    return 0;
}
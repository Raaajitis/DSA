#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int maxArea(int arr[], int n) {

    int left = 0, right = n - 1;
    int maxWater = 0;

    while (left < right) {

        int height = min(arr[left], arr[right]);
        int width = right - left;

        int area = height * width;

        if (area > maxWater)
            maxWater = area;

        if (arr[left] < arr[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

int main() {

    int arr[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max Water: %d\n", maxArea(arr,n));

    return 0;
}
#include <stdio.h>

int trapWater(int height[], int n) {

    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int totalWater = 0;

    while (left < right) {

        if (height[left] <= height[right]) {

            if (height[left] >= leftMax) {

                leftMax = height[left];

            } else {

                totalWater += leftMax - height[left];
            }

            left++;
        }
        else {

            if (height[right] >= rightMax) {

                rightMax = height[right];

            } else {

                totalWater += rightMax - height[right];
            }

            right--;
        }
    }

    return totalWater;
}

int main() {

    int height[] = {4, 2, 0, 3, 2, 5};

    int n = sizeof(height) / sizeof(height[0]);

    int result = trapWater(height, n);

    printf("Total trapped water: %d\n", result);

    return 0;
}
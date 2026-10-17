#include <stdio.h>

int maxArea(int height[], int n) {

    int left = 0;
    int right = n - 1;

    int maximumArea = 0;

    while (left < right) {

        int width = right - left;

        int currentHeight;

        if (height[left] < height[right]) {
            currentHeight = height[left];
        }
        else {
            currentHeight = height[right];
        }

        int area = width * currentHeight;

        if (area > maximumArea) {
            maximumArea = area;
        }

        // Move the shorter line
        if (height[left] < height[right]) {

            left++;

        } else {

            right--;
        }
    }

    return maximumArea;
}

int main() {

    int height[] = {
        1, 8, 6, 2, 5, 4, 8, 3, 7
    };

    int n = sizeof(height) / sizeof(height[0]);

    int result = maxArea(height, n);

    printf("Maximum water area: %d\n", result);

    return 0;
}
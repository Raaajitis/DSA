#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int largestRectangle(int heights[], int n) {

    int stack[n], top = -1;
    int maxArea = 0;
    int i = 0;

    while (i < n) {

        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = max(maxArea, h * width);
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        maxArea = max(maxArea, h * width);
    }

    return maxArea;
}

int main() {

    int arr[] = {2,1,5,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max Area: %d\n", largestRectangle(arr,n));

    return 0;
}
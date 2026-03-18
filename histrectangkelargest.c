#include <stdio.h>

#define MAX 100

int largestRectangle(int heights[], int n) {

    int stack[MAX];
    int top = -1;
    int maxArea = 0;
    int i = 0;

    while (i < n) {

        if (top == -1 || heights[stack[top]] <= heights[i]) {
            stack[++top] = i++;
        } else {
            int h = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = h * width;

            if (area > maxArea)
                maxArea = area;
        }
    }

    while (top != -1) {
        int h = heights[stack[top--]];
        int width = (top == -1) ? i : i - stack[top] - 1;
        int area = h * width;

        if (area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

int main() {

    int arr[] = {2,1,5,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max Area: %d\n", largestRectangle(arr,n));

    return 0;
}
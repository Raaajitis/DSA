#include <stdio.h>

int largestRectangle(int heights[], int n) {

    int stack[n];
    int top = -1;

    int maxArea = 0;
    int i = 0;

    while (i < n) {

        // Push if stack is empty or heights are increasing
        if (top == -1 ||
            heights[stack[top]] <= heights[i]) {

            stack[++top] = i;
            i++;
        }

        else {

            int heightIndex = stack[top--];

            int height = heights[heightIndex];

            int width;

            if (top == -1) {
                width = i;
            }
            else {
                width = i - stack[top] - 1;
            }

            int area = height * width;

            if (area > maxArea) {
                maxArea = area;
            }
        }
    }

    // Process remaining bars
    while (top != -1) {

        int heightIndex = stack[top--];

        int height = heights[heightIndex];

        int width;

        if (top == -1) {
            width = i;
        }
        else {
            width = i - stack[top] - 1;
        }

        int area = height * width;

        if (area > maxArea) {
            maxArea = area;
        }
    }

    return maxArea;
}

int main() {

    int heights[] = {2, 1, 5, 6, 2, 3};

    int n = sizeof(heights) / sizeof(heights[0]);

    int result = largestRectangle(heights, n);

    printf("Largest rectangle area: %d\n", result);

    return 0;
}
#include <stdio.h>

#define MAX 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int largestRectangle(int arr[], int n) {

    int stack[MAX], top = -1;
    int maxArea = 0;
    int i = 0;

    while (i < n) {

        if (top == -1 || arr[stack[top]] <= arr[i]) {
            stack[++top] = i++;
        } else {

            int h = arr[stack[top--]];
            int w = (top == -1) ? i : i - stack[top] - 1;

            maxArea = max(maxArea, h * w);
        }
    }

    while (top != -1) {

        int h = arr[stack[top--]];
        int w = (top == -1) ? i : i - stack[top] - 1;

        maxArea = max(maxArea, h * w);
    }

    return maxArea;
}

int main() {

    int arr[] = {2,1,5,6,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max Area: %d\n", largestRectangle(arr,n));

    return 0;
}
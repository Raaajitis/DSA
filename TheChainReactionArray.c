#include <stdio.h>
#include <stdlib.h>

int main() {

    int arr[] = {1,2,5,6,7,8};

    int n = sizeof(arr)/sizeof(arr[0]);

    int stack[100];
    int top = -1;

    for(int i = 0; i < n; i++) {

        if(top >= 0 &&
           abs(stack[top] - arr[i]) == 1) {

            top--;
        }
        else {

            stack[++top] = arr[i];
        }
    }

    if(top == -1) {

        printf("Empty Array\n");
    }
    else {

        for(int i = 0; i <= top; i++)
            printf("%d ", stack[i]);
    }

    return 0;
}
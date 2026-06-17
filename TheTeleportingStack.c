#include <stdio.h>

int main() {

    int stack[100];
    int top = -1;

    stack[++top] = 5;
    stack[++top] = 3;
    stack[++top] = 1;
    stack[++top] = 3;

    int popped = stack[top--];

    int idx = -1;

    for(int i=top;i>=0;i--) {

        if(stack[i] == popped) {

            idx = i;
            break;
        }
    }

    if(idx != -1) {

        int val = stack[idx];

        for(int i=idx;i<top;i++)
            stack[i] = stack[i+1];

        stack[top] = val;
    }

    printf("Top = %d\n",
           stack[top]);

    return 0;
}
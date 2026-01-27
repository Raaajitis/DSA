#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int top = -1;

// Function to push an element into stack
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed into stack\n", value);
}

// Function to pop an element from stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    pop();
    pop();

    return 0;
}

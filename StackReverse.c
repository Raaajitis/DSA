#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void insertAtBottom(int x) {
    if (isEmpty()) {
        push(x);
        return;
    }

    int temp = pop();
    insertAtBottom(x);
    push(temp);
}

void reverseStack() {
    if (isEmpty())
        return;

    int temp = pop();
    reverseStack();
    insertAtBottom(temp);
}

void printStack() {
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
}

int main() {

    push(1);
    push(2);
    push(3);
    push(4);

    reverseStack();

    printf("Reversed Stack: ");
    printStack();

    return 0;
}
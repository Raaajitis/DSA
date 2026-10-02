#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {

    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

int pop() {

    if (top == -1) {
        return -1;
    }

    return stack[top--];
}

void insertSorted(int value) {

    // Insert if stack is empty or top is smaller
    if (top == -1 || stack[top] <= value) {

        push(value);
        return;
    }

    int temp = pop();

    insertSorted(value);

    push(temp);
}

void sortStack() {

    // Base case
    if (top == -1) {
        return;
    }

    int temp = pop();

    // Sort remaining stack
    sortStack();

    // Insert removed element correctly
    insertSorted(temp);
}

void display() {

    printf("Top -> ");

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main() {

    push(3);
    push(1);
    push(4);
    push(2);

    printf("Original Stack:\n");
    display();

    sortStack();

    printf("\nSorted Stack:\n");
    display();

    return 0;
}
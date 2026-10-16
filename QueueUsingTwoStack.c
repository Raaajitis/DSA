#include <stdio.h>

#define MAX 100

int stack1[MAX];
int stack2[MAX];

int top1 = -1;
int top2 = -1;

void push1(int value) {

    if (top1 == MAX - 1) {
        printf("Queue is full.\n");
        return;
    }

    stack1[++top1] = value;
}

void push2(int value) {

    stack2[++top2] = value;
}

int pop1() {

    if (top1 == -1) {
        return -1;
    }

    return stack1[top1--];
}

int pop2() {

    if (top2 == -1) {
        return -1;
    }

    return stack2[top2--];
}

void transfer() {

    while (top1 != -1) {

        int value = pop1();

        push2(value);
    }
}

void enqueue(int value) {

    push1(value);

    printf("%d inserted into queue.\n", value);
}

int dequeue() {

    if (top2 == -1) {
        transfer();
    }

    if (top2 == -1) {
        printf("Queue is empty.\n");
        return -1;
    }

    return pop2();
}

int peek() {

    if (top2 == -1) {
        transfer();
    }

    if (top2 == -1) {
        printf("Queue is empty.\n");
        return -1;
    }

    return stack2[top2];
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("\nRemoved: %d\n", dequeue());

    printf("Front element: %d\n", peek());

    enqueue(40);

    printf("\nRemoved: %d\n", dequeue());
    printf("Removed: %d\n", dequeue());

    printf("Front element: %d\n", peek());

    return 0;
}
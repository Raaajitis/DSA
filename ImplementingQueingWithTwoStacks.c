#include <stdio.h>

#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) {
    s1[++top1] = x;
}

int pop1() {
    return s1[top1--];
}

void push2(int x) {
    s2[++top2] = x;
}

int pop2() {
    return s2[top2--];
}

void enqueue(int x) {
    push1(x);
}

int dequeue() {

    if (top2 == -1) {
        while (top1 != -1)
            push2(pop1());
    }

    if (top2 == -1)
        return -1;

    return pop2();
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());

    return 0;
}
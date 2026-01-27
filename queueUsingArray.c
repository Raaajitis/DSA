#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to insert an element into queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("%d removed from queue\n", queue[front]);
    front++;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    return 0;
}

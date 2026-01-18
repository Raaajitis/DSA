#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
int isFull() {
return ((rear + 1) % SIZE == front);
}
int isEmpty() {
return (front == -1);
}
int main() {
int choice, value;
do {
printf("\nCircular Queue Operations:\n");
printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
if (isFull()) {
printf("Queue is Full! Cannot enqueue\n");
} else {
printf("Enter value to insert: ");
scanf("%d", &value);
if (isEmpty()) {
    front = rear = 0;
} else {
rear = (rear + 1) % SIZE;
}
queue[rear] = value;
printf("Inserted %d into the queue\n", value);
}
break;
case 2:
if (isEmpty()) {
printf("Queue is Empty! Cannot dequeue\n");
} else {
printf("Dequeued %d from the queue\n", queue[front]);
if (front == rear) {
front = rear = -1;
} else {
front = (front + 1) % SIZE;
}
}
break;
case 3:
if (isEmpty()) {
printf("Queue is Empty!\n");
} else {
int i = front;
printf("Queue elements: ");
do {
printf("%d ", queue[i]);
if (i == rear)
break;
i = (i + 1) % SIZE;
} while (1);
printf("\n");
}
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid choice! Please enter a valid option.\n");
}
} while (choice != 4);
return 0;
}

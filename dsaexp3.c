#include <stdio.h>
#define MAX 5

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, value;

    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (rear == MAX - 1) {
                    printf("Queue Overflow! Cannot enqueue more elements.\n");
                } else {
                    printf("Enter the value to enqueue: ");
                    scanf("%d", &value);

                    if (front == -1)  
                        front = 0; 
                    
                    rear++;
                    queue[rear] = value;
                    printf("%d enqueued into the queue.\n", value);
                }
                break;

            case 2: // Dequeue
                if (front == -1 || front > rear) {
                    printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
                    front = rear = -1;  
                } else {
                    printf("%d dequeued from the queue.\n", queue[front]);
                    front++;  

                    if (front > rear) 
                        front = rear = -1;  
                }
                break;

            case 3: // Display
                if (front == -1 || front > rear) {
                    printf("The queue is empty.\n");
                } else {
                    printf("Current queue elements: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
                break;

            case 4: // Exit
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
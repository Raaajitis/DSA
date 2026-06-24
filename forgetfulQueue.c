#include <stdio.h>

#define MAX 100

int main() {

    int queue[MAX] = {2, 1, 2};
    int front = 0, rear = 3;
    int K = 5;

    int removed[MAX] = {0};

    for (int step = 0; step < K && front < rear; step++) {

        int x = queue[front++];

        if (removed[x] == 0) {
            removed[x] = 1;
        } else {
            queue[rear++] = x + 1;
        }
    }

    if (front == rear) {
        printf("Empty Queue\n");
    } else {
        printf("Queue: ");
        while (front < rear)
            printf("%d ", queue[front++]);
    }

    return 0;
}
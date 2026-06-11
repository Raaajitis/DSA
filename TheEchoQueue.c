#include <stdio.h>

#define MAX 100

int main() {

    int queue[MAX] = {1,2,3};
    int front = 0;
    int rear = 3;

    int seen[MAX] = {0};

    int K = 10;

    printf("Sequence:\n");

    for(int step = 0; step < K && front < rear; step++) {

        int x = queue[front++];

        printf("%d ", x);

        if(!seen[x]) {

            seen[x] = 1;
            queue[rear++] = x;
        }
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX 100

char dict[MAX][10];
int visited[MAX];

int isValidTransform(char *a, char *b) {

    int diff = 0;

    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i])
            diff++;
    }

    return diff == 1;
}

int wordLadder(char start[], char end[], int n) {

    int queue[MAX], front = 0, rear = 0;
    int level[MAX];

    for (int i = 0; i < n; i++) {
        if (strcmp(dict[i], start) == 0) {
            queue[rear] = i;
            level[rear++] = 1;
            visited[i] = 1;
        }
    }

    while (front < rear) {

        int idx = queue[front];
        int steps = level[front++];

        if (strcmp(dict[idx], end) == 0)
            return steps;

        for (int i = 0; i < n; i++) {

            if (!visited[i] && isValidTransform(dict[idx], dict[i])) {
                visited[i] = 1;
                queue[rear] = i;
                level[rear++] = steps + 1;
            }
        }
    }

    return 0;
}

int main() {

    strcpy(dict[0], "hit");
    strcpy(dict[1], "hot");
    strcpy(dict[2], "dot");
    strcpy(dict[3], "dog");
    strcpy(dict[4], "cog");

    int n = 5;

    printf("Steps: %d\n",
           wordLadder("hit","cog",n));

    return 0;
}
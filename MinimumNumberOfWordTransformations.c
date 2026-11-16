#include <stdio.h>
#include <string.h>

#define WORDS 6
#define LENGTH 4

struct QueueItem {
    int index;
    int steps;
};

int oneCharacterDifferent(char a[], char b[]) {

    int differences = 0;

    for (int i = 0;
         a[i] != '\0' && b[i] != '\0';
         i++) {

        if (a[i] != b[i]) {

            differences++;

            if (differences > 1) {
                return 0;
            }
        }
    }

    return differences == 1;
}

int minimumTransformations(
    char start[],
    char target[],
    char dictionary[WORDS][LENGTH]) {

    if (strcmp(start, target) == 0) {
        return 0;
    }

    int visited[WORDS] = {0};

    struct QueueItem queue[WORDS];

    int front = 0;
    int rear = 0;

    /*
     * Add dictionary words reachable
     * directly from the starting word.
     */
    for (int i = 0; i < WORDS; i++) {

        if (oneCharacterDifferent(
                start,
                dictionary[i])) {

            queue[rear].index = i;
            queue[rear].steps = 1;

            rear++;

            visited[i] = 1;
        }
    }

    while (front < rear) {

        struct QueueItem current =
            queue[front++];

        char *currentWord =
            dictionary[current.index];

        if (strcmp(currentWord, target) == 0) {

            return current.steps;
        }

        for (int i = 0; i < WORDS; i++) {

            if (!visited[i] &&
                oneCharacterDifferent(
                    currentWord,
                    dictionary[i])) {

                visited[i] = 1;

                queue[rear].index = i;
                queue[rear].steps =
                    current.steps + 1;

                rear++;
            }
        }
    }

    return -1;
}

int main() {

    char start[] = "hit";
    char target[] = "cog";

    char dictionary[WORDS][LENGTH] = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    int result =
        minimumTransformations(
            start,
            target,
            dictionary
        );

    if (result == -1) {

        printf("Transformation is impossible.\n");

    } else {

        printf("Minimum transformations: %d\n",
               result);
    }

    return 0;
}
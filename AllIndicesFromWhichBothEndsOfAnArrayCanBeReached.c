#include <stdio.h>

#define MAX 100

int canReach(int jump[],
             int n,
             int current,
             int target,
             int visited[]) {

    if (current == target) {
        return 1;
    }

    visited[current] = 1;

    int left = current - jump[current];
    int right = current + jump[current];

    if (left < 0) {
        left = 0;
    }

    if (right >= n) {
        right = n - 1;
    }

    for (int next = left; next <= right; next++) {

        if (next != current &&
            !visited[next]) {

            if (canReach(
                    jump,
                    n,
                    next,
                    target,
                    visited)) {

                return 1;
            }
        }
    }

    return 0;
}

void findIndices(int jump[], int n) {

    printf("Indices that can reach both ends: ");

    int found = 0;

    for (int i = 0; i < n; i++) {

        int visitedLeft[MAX] = {0};
        int visitedRight[MAX] = {0};

        int reachesLeft =
            canReach(
                jump,
                n,
                i,
                0,
                visitedLeft
            );

        int reachesRight =
            canReach(
                jump,
                n,
                i,
                n - 1,
                visitedRight
            );

        if (reachesLeft && reachesRight) {

            printf("%d ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }

    printf("\n");
}

int main() {

    int jump[] = {1, 2, 1, 2, 1};

    int n = sizeof(jump) / sizeof(jump[0]);

    findIndices(jump, n);

    return 0;
}
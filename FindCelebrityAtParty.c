#include <stdio.h>

#define N 4

int findCelebrity(int knows[N][N]) {

    int candidate = 0;

    // Step 1: Find a possible celebrity
    for (int i = 1; i < N; i++) {

        if (knows[candidate][i] == 1) {
            candidate = i;
        }
    }

    // Step 2: Verify the candidate
    for (int i = 0; i < N; i++) {

        if (i != candidate) {

            // Celebrity should know nobody
            if (knows[candidate][i] == 1) {
                return -1;
            }

            // Everyone should know the celebrity
            if (knows[i][candidate] == 0) {
                return -1;
            }
        }
    }

    return candidate;
}

int main() {

    int knows[N][N] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 0}
    };

    int result = findCelebrity(knows);

    if (result == -1) {
        printf("There is no celebrity.\n");
    }
    else {
        printf("Person %d is the celebrity.\n", result);
    }

    return 0;
}
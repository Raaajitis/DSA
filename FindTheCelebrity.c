#include <stdio.h>

#define N 4

int party[N][N] = {
    {0, 1, 1, 1},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {0, 0, 0, 0}
};

int knows(int a, int b) {
    return party[a][b];
}

int findCelebrity(int n) {

    int candidate = 0;

    // Step 1: Find potential celebrity
    for (int i = 1; i < n; i++) {

        if (knows(candidate, i)) {
            candidate = i;
        }
    }

    // Step 2: Verify candidate
    for (int i = 0; i < n; i++) {

        if (i == candidate)
            continue;

        // Candidate must know nobody
        // Everyone else must know candidate
        if (knows(candidate, i) || !knows(i, candidate))
            return -1;
    }

    return candidate;
}

int main() {

    int celebrity = findCelebrity(N);

    if (celebrity == -1)
        printf("No Celebrity\n");
    else
        printf("Celebrity: %d\n", celebrity);

    return 0;
}
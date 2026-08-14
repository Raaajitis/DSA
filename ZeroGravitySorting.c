#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 8
#define MAXSTATES 40320

typedef struct {
    int a[MAXN];
    int dist;
} State;

State queue[MAXSTATES];

int encode(int a[], int n) {
    int code = 0;

    for (int i = 0; i < n; i++)
        code = code * 10 + (a[i] + 10);

    return code;
}

int isSorted(int a[], int n) {

    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i])
            return 0;
    }

    return 1;
}

int main() {

    int n;
    scanf("%d", &n);

    if (n > MAXN) {
        printf("N must be <= %d for this exact BFS solution.\n", MAXN);
        return 0;
    }

    int start[MAXN];

    for (int i = 0; i < n; i++)
        scanf("%d", &start[i]);

    /*
     * Check whether the starting array is already sorted.
     */
    if (isSorted(start, n)) {
        printf("0\n");
        return 0;
    }

    /*
     * Coordinate-compress the values.
     *
     * This allows every permutation to have
     * a unique encoding.
     */
    int values[MAXN];

    for (int i = 0; i < n; i++)
        values[i] = start[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if (values[i] > values[j]) {
                int t = values[i];
                values[i] = values[j];
                values[j] = t;
            }
        }
    }

    int compressed[MAXN];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (start[i] == values[j]) {
                compressed[i] = j;
                break;
            }
        }
    }

    int target[MAXN];

    for (int i = 0; i < n; i++)
        target[i] = i;

    /*
     * BFS queue.
     */
    int front = 0;
    int back = 0;

    queue[back].dist = 0;

    for (int i = 0; i < n; i++)
        queue[back].a[i] = compressed[i];

    back++;

    /*
     * Since n <= 8, n! <= 40320.
     */
    int totalStates = 1;

    for (int i = 2; i <= n; i++)
        totalStates *= i;

    char *visited =
        calloc(totalStates, sizeof(char));

    /*
     * Encode permutation using factorial numbering.
     */
    int encodePermutation(int a[]) {

        int code = 0;

        for (int i = 0; i < n; i++) {

            int smaller = 0;

            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[i])
                    smaller++;
            }

            code = code * (n - i) + smaller;
        }

        return code;
    }

    visited[encodePermutation(compressed)] = 1;

    while (front < back) {

        State current = queue[front++];

        /*
         * Try every possible consecutive triple.
         */
        for (int i = 0; i <= n - 3; i++) {

            int next[MAXN];

            for (int j = 0; j < n; j++)
                next[j] = current.a[j];

            /*
             * Left rotation:
             *
             * [a,b,c] -> [b,c,a]
             */
            int x = next[i];

            next[i] = next[i + 1];
            next[i + 1] = next[i + 2];
            next[i + 2] = x;

            int code = encodePermutation(next);

            if (!visited[code]) {

                if (isSorted(next, n)) {

                    printf("%d\n", current.dist + 1);

                    free(visited);
                    return 0;
                }

                visited[code] = 1;

                queue[back].dist =
                    current.dist + 1;

                for (int j = 0; j < n; j++)
                    queue[back].a[j] = next[j];

                back++;
            }
        }
    }

    /*
     * No solution.
     */
    printf("-1\n");

    free(visited);

    return 0;
}
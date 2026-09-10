#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int column;
    int broken;
    int distance;
} State;

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    char **grid = malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++) {
        grid[i] = malloc((m + 1) * sizeof(char));
        scanf("%s", grid[i]);
    }

    /*
     * visited[(row * m + column) * 2 + broken]
     */
    int totalStates = n * m * 2;
    char *visited = calloc(totalStates, sizeof(char));
    State *queue = malloc(totalStates * sizeof(State));

    int front = 0;
    int back = 0;

    queue[back++] = (State){0, 0, 0, 0};
    visited[0] = 1;

    int rowChange[] = {-1, 1, 0, 0};
    int columnChange[] = {0, 0, -1, 1};
    int answer = -1;

    while (front < back) {
        State current = queue[front++];

        if (current.row == n - 1 && current.column == m - 1) {
            answer = current.distance;
            break;
        }

        for (int direction = 0; direction < 4; direction++) {
            int newRow = current.row + rowChange[direction];
            int newColumn = current.column + columnChange[direction];

            if (newRow < 0 || newRow >= n ||
                newColumn < 0 || newColumn >= m) {
                continue;
            }

            int newBroken = current.broken;

            if (grid[newRow][newColumn] == '1') {
                if (current.broken) {
                    continue;
                }

                newBroken = 1;
            }

            int index = (newRow * m + newColumn) * 2 + newBroken;

            if (!visited[index]) {
                visited[index] = 1;

                queue[back++] = (State){
                    newRow,
                    newColumn,
                    newBroken,
                    current.distance + 1
                };
            }
        }
    }

    printf("%d\n", answer);

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }

    free(grid);
    free(visited);
    free(queue);

    return 0;
}
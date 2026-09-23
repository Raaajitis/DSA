#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    char **grid = malloc(n * sizeof(char *));
    int totalCells = n * m;

    int *queue = malloc(totalCells * sizeof(int));
    int *fireTime = malloc(totalCells * sizeof(int));
    int *personTime = malloc(totalCells * sizeof(int));

    int start = -1;
    int exitCell = -1;

    for (int i = 0; i < totalCells; i++) {
        fireTime[i] = INT_MAX;
        personTime[i] = -1;
    }

    int front = 0;
    int back = 0;

    for (int row = 0; row < n; row++) {
        grid[row] = malloc((m + 1) * sizeof(char));
        scanf("%s", grid[row]);

        for (int column = 0; column < m; column++) {
            int index = row * m + column;

            if (grid[row][column] == 'F') {
                fireTime[index] = 0;
                queue[back++] = index;
            } else if (grid[row][column] == 'S') {
                start = index;
            } else if (grid[row][column] == 'E') {
                exitCell = index;
            }
        }
    }

    int rowChange[] = {-1, 1, 0, 0};
    int columnChange[] = {0, 0, -1, 1};

    /*
     * Multi-source BFS for fire arrival times.
     */
    while (front < back) {
        int current = queue[front++];
        int row = current / m;
        int column = current % m;

        for (int direction = 0; direction < 4; direction++) {
            int newRow = row + rowChange[direction];
            int newColumn = column + columnChange[direction];

            if (newRow < 0 || newRow >= n ||
                newColumn < 0 || newColumn >= m) {
                continue;
            }

            if (grid[newRow][newColumn] == '#') {
                continue;
            }

            int next = newRow * m + newColumn;

            if (fireTime[next] == INT_MAX) {
                fireTime[next] = fireTime[current] + 1;
                queue[back++] = next;
            }
        }
    }

    /*
     * BFS for the person.
     */
    front = 0;
    back = 0;

    queue[back++] = start;
    personTime[start] = 0;

    while (front < back) {
        int current = queue[front++];

        if (current == exitCell) {
            break;
        }

        int row = current / m;
        int column = current % m;

        for (int direction = 0; direction < 4; direction++) {
            int newRow = row + rowChange[direction];
            int newColumn = column + columnChange[direction];

            if (newRow < 0 || newRow >= n ||
                newColumn < 0 || newColumn >= m) {
                continue;
            }

            if (grid[newRow][newColumn] == '#') {
                continue;
            }

            int next = newRow * m + newColumn;

            if (personTime[next] != -1) {
                continue;
            }

            int arrivalTime = personTime[current] + 1;

            if (arrivalTime < fireTime[next]) {
                personTime[next] = arrivalTime;
                queue[back++] = next;
            }
        }
    }

    printf("%d\n", personTime[exitCell]);

    for (int row = 0; row < n; row++) {
        free(grid[row]);
    }

    free(grid);
    free(queue);
    free(fireTime);
    free(personTime);

    return 0;
}
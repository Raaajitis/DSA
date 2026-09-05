#include <stdio.h>

#define MAX 100

int grid[MAX][MAX];
int id[MAX][MAX];
int area[MAX * MAX];

int n;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, int islandId) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return 0;

    if (grid[x][y] == 0 || id[x][y] != 0)
        return 0;

    id[x][y] = islandId;

    int size = 1;

    for (int d = 0; d < 4; d++)
        size += dfs(x + dx[d], y + dy[d], islandId);

    return size;
}

int maxIsland() {
    int islandId = 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && id[i][j] == 0) {
                islandId++;

                area[islandId] = dfs(i, j, islandId);

                if (area[islandId] > maxArea)
                    maxArea = area[islandId];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == 0) {
                int total = 1;
                int used[4];
                int usedCount = 0;

                for (int d = 0; d < 4; d++) {
                    int x = i + dx[d];
                    int y = j + dy[d];

                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        int currentId = id[x][y];

                        if (currentId != 0) {
                            int alreadyUsed = 0;

                            for (int k = 0; k < usedCount; k++) {
                                if (used[k] == currentId) {
                                    alreadyUsed = 1;
                                    break;
                                }
                            }

                            if (!alreadyUsed) {
                                total += area[currentId];
                                used[usedCount++] = currentId;
                            }
                        }
                    }
                }

                if (total > maxArea)
                    maxArea = total;
            }
        }
    }

    return maxArea;
}

int main() {
    int input[MAX][MAX] = {
        {1, 0},
        {0, 1}
    };

    n = 2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = input[i][j];

    printf("Largest Island: %d\n", maxIsland());

    return 0;
}
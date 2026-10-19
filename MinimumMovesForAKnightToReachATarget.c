#include <stdio.h>

#define N 8
#define MAX 100

struct Position {

    int row;
    int col;
    int moves;
};

int minimumKnightMoves(int startRow,
                       int startCol,
                       int targetRow,
                       int targetCol) {

    int visited[N][N] = {0};

    struct Position queue[MAX];

    int front = 0;
    int rear = 0;

    int rowMove[8] = {
        2, 2, -2, -2,
        1, 1, -1, -1
    };

    int colMove[8] = {
        1, -1, 1, -1,
        2, -2, 2, -2
    };

    queue[rear].row = startRow;
    queue[rear].col = startCol;
    queue[rear].moves = 0;

    rear++;

    visited[startRow][startCol] = 1;

    while (front < rear) {

        struct Position current =
            queue[front++];

        if (current.row == targetRow &&
            current.col == targetCol) {

            return current.moves;
        }

        for (int i = 0; i < 8; i++) {

            int newRow =
                current.row + rowMove[i];

            int newCol =
                current.col + colMove[i];

            if (newRow >= 0 &&
                newRow < N &&
                newCol >= 0 &&
                newCol < N &&
                visited[newRow][newCol] == 0) {

                visited[newRow][newCol] = 1;

                queue[rear].row = newRow;
                queue[rear].col = newCol;

                queue[rear].moves =
                    current.moves + 1;

                rear++;
            }
        }
    }

    return -1;
}

int main() {

    int startRow = 0;
    int startCol = 0;

    int targetRow = 7;
    int targetCol = 7;

    int result =
        minimumKnightMoves(
            startRow,
            startCol,
            targetRow,
            targetCol
        );

    printf("Minimum knight moves: %d\n",
           result);

    return 0;
}
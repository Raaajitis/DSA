#include <stdio.h>
#include <string.h>

#define ROWS 3
#define COLS 4

int searchWord(char board[ROWS][COLS],
               char word[],
               int row,
               int col,
               int index) {

    // Entire word has been matched
    if (word[index] == '\0') {
        return 1;
    }

    // Check boundaries
    if (row < 0 || row >= ROWS ||
        col < 0 || col >= COLS) {

        return 0;
    }

    // Current character does not match
    if (board[row][col] != word[index]) {
        return 0;
    }

    // Save current character
    char original = board[row][col];

    // Mark cell as visited
    board[row][col] = '#';

    // Search all four directions
    int found =
        searchWord(board, word,
                   row - 1, col, index + 1)
        ||
        searchWord(board, word,
                   row + 1, col, index + 1)
        ||
        searchWord(board, word,
                   row, col - 1, index + 1)
        ||
        searchWord(board, word,
                   row, col + 1, index + 1);

    // Backtrack: restore original character
    board[row][col] = original;

    return found;
}

int wordExists(char board[ROWS][COLS],
               char word[]) {

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            if (board[i][j] == word[0]) {

                if (searchWord(board,
                               word,
                               i,
                               j,
                               0)) {

                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {

    char board[ROWS][COLS] = {

        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}

    };

    char word[] = "ABCCED";

    if (wordExists(board, word)) {

        printf("Word exists.\n");

    } else {

        printf("Word does not exist.\n");
    }

    return 0;
}
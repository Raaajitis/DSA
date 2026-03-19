#include <stdio.h>

#define ROW 3
#define COL 4

int dfs(char board[ROW][COL], char* word, int i, int j, int k) {

    if (word[k] == '\0')
        return 1;

    if (i < 0 || j < 0 || i >= ROW || j >= COL || board[i][j] != word[k])
        return 0;

    char temp = board[i][j];
    board[i][j] = '#'; // mark visited

    int found = dfs(board, word, i+1, j, k+1) ||
                dfs(board, word, i-1, j, k+1) ||
                dfs(board, word, i, j+1, k+1) ||
                dfs(board, word, i, j-1, k+1);

    board[i][j] = temp; // backtrack

    return found;
}

int exist(char board[ROW][COL], char* word) {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (dfs(board, word, i, j, 0))
                return 1;
        }
    }
    return 0;
}

int main() {

    char board[ROW][COL] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    char word[] = "ABCCED";

    if (exist(board, word))
        printf("Word Found\n");
    else
        printf("Word Not Found\n");

    return 0;
}
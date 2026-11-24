#include <stdio.h>
#include <string.h>

#define MAX 100

int isInterleaving(char A[],
                   char B[],
                   char C[]) {

    int n = strlen(A);
    int m = strlen(B);
    int lengthC = strlen(C);

    // Length must match
    if (n + m != lengthC) {
        return 0;
    }

    int dp[MAX][MAX] = {0};

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= m; j++) {

            if (i == 0 && j == 0) {
                continue;
            }

            int position = i + j - 1;

            // Take character from A
            if (i > 0 &&
                A[i - 1] == C[position] &&
                dp[i - 1][j]) {

                dp[i][j] = 1;
            }

            // Take character from B
            if (j > 0 &&
                B[j - 1] == C[position] &&
                dp[i][j - 1]) {

                dp[i][j] = 1;
            }
        }
    }

    return dp[n][m];
}

int main() {

    char A[] = "abc";
    char B[] = "def";
    char C[] = "adbcef";

    if (isInterleaving(A, B, C)) {

        printf("Valid interleaving.\n");

    } else {

        printf("Not a valid interleaving.\n");
    }

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define N 3

int min3(int a, int b, int c) {

    int minimum = a;

    if (b < minimum)
        minimum = b;

    if (c < minimum)
        minimum = c;

    return minimum;
}

int minimumFallingPath(int matrix[N][N]) {

    int dp[N][N];

    // First row
    for (int j = 0; j < N; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Remaining rows
    for (int i = 1; i < N; i++) {

        for (int j = 0; j < N; j++) {

            int above = dp[i - 1][j];

            int upperLeft = INT_MAX;
            int upperRight = INT_MAX;

            if (j > 0) {
                upperLeft = dp[i - 1][j - 1];
            }

            if (j < N - 1) {
                upperRight = dp[i - 1][j + 1];
            }

            dp[i][j] =
                matrix[i][j] +
                min3(
                    above,
                    upperLeft,
                    upperRight
                );
        }
    }

    // Find minimum value in final row
    int answer = dp[N - 1][0];

    for (int j = 1; j < N; j++) {

        if (dp[N - 1][j] < answer) {
            answer = dp[N - 1][j];
        }
    }

    return answer;
}

int main() {

    int matrix[N][N] = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };

    int result =
        minimumFallingPath(matrix);

    printf("Minimum falling path sum: %d\n",
           result);

    return 0;
}
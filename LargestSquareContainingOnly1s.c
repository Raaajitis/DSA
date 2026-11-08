#include <stdio.h>

#define ROWS 4
#define COLS 5

int min3(int a, int b, int c) {

    int minimum = a;

    if (b < minimum)
        minimum = b;

    if (c < minimum)
        minimum = c;

    return minimum;
}

int largestSquare(int matrix[ROWS][COLS]) {

    int dp[ROWS][COLS];

    int maxSide = 0;

    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {

            if (matrix[i][j] == 0) {

                dp[i][j] = 0;
            }

            else if (i == 0 || j == 0) {

                dp[i][j] = 1;
            }

            else {

                dp[i][j] =
                    1 + min3(
                        dp[i - 1][j],
                        dp[i][j - 1],
                        dp[i - 1][j - 1]
                    );
            }

            if (dp[i][j] > maxSide) {
                maxSide = dp[i][j];
            }
        }
    }

    return maxSide * maxSide;
}

int main() {

    int matrix[ROWS][COLS] = {

        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}

    };

    int result = largestSquare(matrix);

    printf("Area of largest square: %d\n", result);

    return 0;
}
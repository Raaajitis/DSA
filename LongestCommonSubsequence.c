#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    char X[] = "ABCDA";
    char Y[] = "ACDB";

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

    // Build DP table
    for (int i = 0; i <= m; i++) {

        for (int j = 0; j <= n; j++) {

            // Base case
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            // If characters match
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            // If not match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("Length of LCS = %d", dp[m][n]);

    return 0;
}

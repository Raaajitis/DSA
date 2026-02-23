#include <stdio.h>
#include <string.h>

int main() {

    char S[] = "rabbbit";
    char T[] = "rabbit";

    int m = strlen(S);
    int n = strlen(T);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = 1;

    for (int j = 1; j <= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (S[i - 1] == T[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    printf("Distinct Subsequences = %d", dp[m][n]);

    return 0;
}
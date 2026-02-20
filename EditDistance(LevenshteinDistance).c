#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}

int main() {

    char str1[] = "horse";
    char str2[] = "ros";

    int m = strlen(str1);
    int n = strlen(str2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min(
                    dp[i][j - 1],     // insert
                    dp[i - 1][j],     // delete
                    dp[i - 1][j - 1]  // replace
                );
        }
    }

    printf("Minimum operations = %d", dp[m][n]);

    return 0;
}
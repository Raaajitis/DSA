#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int x = (a < b) ? a : b;
    return (x < c) ? x : c;
}

int editDistance(char *a, char *b) {

    int n = strlen(a);
    int m = strlen(b);

    int dp[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(
                    dp[i][j-1],    // insert
                    dp[i-1][j],    // delete
                    dp[i-1][j-1]   // replace
                );
        }
    }

    return dp[n][m];
}

int main() {

    char a[] = "horse";
    char b[] = "ros";

    printf("Edit Distance: %d\n", editDistance(a,b));

    return 0;
}
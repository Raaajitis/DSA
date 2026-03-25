#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < c) return b;
    return c;
}

int editDistance(char s1[], char s2[]) {

    int n = strlen(s1);
    int m = strlen(s2);

    int dp[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j],    // delete
                                   dp[i][j-1],    // insert
                                   dp[i-1][j-1]); // replace
        }
    }

    return dp[n][m];
}

int main() {

    char s1[] = "horse";
    char s2[] = "ros";

    printf("Edit Distance: %d\n", editDistance(s1, s2));

    return 0;
}
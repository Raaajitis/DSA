#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {

    int x = (a < b) ? a : b;
    return (x < c) ? x : c;
}

int editDistance(char s1[], char s2[]) {

    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = 1 + min(
                    dp[i][j-1],
                    dp[i-1][j],
                    dp[i-1][j-1]
                );
        }
    }

    return dp[m][n];
}

int main() {

    char s1[] = "horse";
    char s2[] = "ros";

    printf("Edit Distance: %d\n",
           editDistance(s1,s2));

    return 0;
}
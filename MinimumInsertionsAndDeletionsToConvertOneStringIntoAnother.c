#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b) {

    return (a > b) ? a : b;
}

int findLCS(char str1[], char str2[]) {

    int n = strlen(str1);
    int m = strlen(str2);

    int dp[MAX][MAX] = {0};

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            if (str1[i - 1] == str2[j - 1]) {

                dp[i][j] =
                    1 + dp[i - 1][j - 1];

            } else {

                dp[i][j] =
                    max(dp[i - 1][j],
                        dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

void minimumOperations(char str1[],
                       char str2[]) {

    int n = strlen(str1);
    int m = strlen(str2);

    int lcs = findLCS(str1, str2);

    int deletions = n - lcs;
    int insertions = m - lcs;

    printf("Minimum deletions: %d\n",
           deletions);

    printf("Minimum insertions: %d\n",
           insertions);

    printf("Total operations: %d\n",
           deletions + insertions);
}

int main() {

    char str1[] = "heap";
    char str2[] = "pea";

    minimumOperations(str1, str2);

    return 0;
}
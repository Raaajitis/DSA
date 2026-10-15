#include <stdio.h>
#include <string.h>

#define MAX 100

int max(int a, int b) {

    if (a > b) {
        return a;
    }

    return b;
}

int longestPalindromicSubsequence(char str[]) {

    int n = strlen(str);

    if (n == 0) {
        return 0;
    }

    int dp[MAX][MAX] = {0};

    // Every single character is a palindrome
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // length represents current substring length
    for (int length = 2; length <= n; length++) {

        for (int i = 0; i <= n - length; i++) {

            int j = i + length - 1;

            if (str[i] == str[j]) {

                if (length == 2) {
                    dp[i][j] = 2;
                }
                else {
                    dp[i][j] =
                        2 + dp[i + 1][j - 1];
                }
            }
            else {

                dp[i][j] =
                    max(dp[i + 1][j],
                        dp[i][j - 1]);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {

    char str[] = "bbbab";

    int result =
        longestPalindromicSubsequence(str);

    printf("Longest palindromic subsequence length: %d\n",
           result);

    return 0;
}
#include <stdio.h>
#include <string.h>

int isPalindrome(char str[], int i, int j) {
    while (i < j) {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int minCuts(char str[]) {

    int n = strlen(str);
    int dp[n];

    for (int i = 0; i < n; i++)
        dp[i] = i; // max cuts

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {

            if (isPalindrome(str, j, i)) {

                if (j == 0)
                    dp[i] = 0;
                else if (dp[j-1] + 1 < dp[i])
                    dp[i] = dp[j-1] + 1;
            }
        }
    }

    return dp[n-1];
}

int main() {

    char str[] = "aab";

    printf("Minimum Cuts: %d\n", minCuts(str));

    return 0;
}
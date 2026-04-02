#include <stdio.h>
#include <string.h>

int wordBreak(char str[], char *dict[], int dictSize) {

    int n = strlen(str);
    int dp[n+1];

    for (int i = 0; i <= n; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {

            if (dp[j]) {

                char temp[100];
                strncpy(temp, str + j, i - j);
                temp[i - j] = '\0';

                for (int k = 0; k < dictSize; k++) {
                    if (strcmp(temp, dict[k]) == 0) {
                        dp[i] = 1;
                        break;
                    }
                }

                if (dp[i]) break;
            }
        }
    }

    return dp[n];
}

int main() {

    char str[] = "leetcode";
    char *dict[] = {"leet", "code"};

    if (wordBreak(str, dict, 2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
#include <stdio.h>
#include <string.h>

int wordExists(char *word) {
    return strcmp(word, "leet") == 0 ||
           strcmp(word, "code") == 0;
}

int main() {

    char str[] = "leetcode";
    int n = strlen(str);

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j < i; j++) {

            if (dp[j]) {

                char temp[100];
                strncpy(temp, str + j, i - j);
                temp[i - j] = '\0';

                if (wordExists(temp)) {
                    dp[i] = 1;
                    break;
                }
            }
        }
    }

    if (dp[n])
        printf("Can be segmented");
    else
        printf("Cannot be segmented");

    return 0;
}
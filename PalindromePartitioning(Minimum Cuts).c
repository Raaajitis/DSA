#include <stdio.h>
#include <string.h>
#include <limits.h>

int isPalindrome(char str[], int i, int j) {

    while (i < j) {
        if (str[i] != str[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {

    char str[] = "aab";
    int n = strlen(str);

    int dp[n];

    // DP for minimum cuts
    for (int i = 0; i < n; i++) {

        if (isPalindrome(str, 0, i)) {
            dp[i] = 0;
        }
        else {

            dp[i] = INT_MAX;

            for (int j = 0; j < i; j++) {

                if (isPalindrome(str, j + 1, i) && dp[j] + 1 < dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    printf("Minimum cuts = %d", dp[n - 1]);

    return 0;
}

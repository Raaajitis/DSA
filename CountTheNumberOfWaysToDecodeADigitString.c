#include <stdio.h>
#include <string.h>

#define MAX 100

long long countDecodings(char str[]) {

    int n = strlen(str);

    if (n == 0 || str[0] == '0') {
        return 0;
    }

    long long dp[MAX + 1] = {0};

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {

        // Current single digit
        if (str[i - 1] != '0') {

            dp[i] += dp[i - 1];
        }

        // Previous two digits
        int twoDigit =
            (str[i - 2] - '0') * 10 +
            (str[i - 1] - '0');

        if (twoDigit >= 10 &&
            twoDigit <= 26) {

            dp[i] += dp[i - 2];
        }
    }

    return dp[n];
}

int main() {

    char str[] = "226";

    long long result =
        countDecodings(str);

    printf("Number of decoding ways: %lld\n",
           result);

    return 0;
}
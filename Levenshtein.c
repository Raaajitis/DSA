#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) smallest = b;
    if (c < smallest) smallest = c;
    return smallest;
}

int main() {

    char X[] = "horse";
    char Y[] = "ros";

    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

    // Build DP table
    for (int i = 0; i <= m; i++) {

        for (int j = 0; j <= n; j++) {

            // If first string is empty → insert all chars
            if (i == 0)
                dp[i][j] = j;

            // If second string is empty → delete all chars
            else if (j == 0)
                dp[i][j] = i;

            // If characters match → no extra cost
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            // If characters don't match → choose min operation
            else
                dp[i][j] = 1 + min(
                    dp[i][j - 1],     // Insert
                    dp[i - 1][j],     // Delete
                    dp[i - 1][j - 1]  // Replace
                );
        }
    }

    printf("Edit Distance = %d", dp[m][n]);

    return 0;
}

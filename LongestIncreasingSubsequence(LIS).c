#include <stdio.h>

int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = 8;

    int dp[n];

    // Every element alone is LIS of length 1
    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max = dp[0];

    for (int i = 1; i < n; i++)
        if (dp[i] > max)
            max = dp[i];

    printf("Length of LIS = %d", max);

    return 0;
}

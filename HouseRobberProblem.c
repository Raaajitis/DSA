#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {

    int arr[] = {2, 7, 9, 3, 1};
    int n = 5;

    if (n == 0) return 0;
    if (n == 1) {
        printf("%d", arr[0]);
        return 0;
    }

    int dp[n];

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    printf("Maximum money = %d", dp[n - 1]);

    return 0;
}
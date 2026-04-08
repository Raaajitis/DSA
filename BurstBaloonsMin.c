#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCoins(int arr[], int n) {

    int dp[100][100] = {0};

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {

            int j = i + len - 1;

            for (int k = i; k <= j; k++) {

                int left = (k == i) ? 0 : dp[i][k-1];
                int right = (k == j) ? 0 : dp[k+1][j];

                int val = left + right + arr[k];

                dp[i][j] = max(dp[i][j], val);
            }
        }
    }

    return dp[0][n-1];
}

int main() {

    int arr[] = {3,1,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Max Coins: %d\n", maxCoins(arr,n));

    return 0;
}
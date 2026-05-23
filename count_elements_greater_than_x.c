#include <stdio.h>

int upperBound(int arr[], int n, int x) {
    int l = 0, r = n - 1, ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] > x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int countGreater(int mat[][3], int n, int m, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int idx = upperBound(mat[i], m, x);
        count += (m - idx);
    }
    return count;
}

int main() {
    int mat[3][3] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 12}
    };

    int x = 5;
    printf("Count = %d\n", countGreater(mat, 3, 3, x));
    return 0;
}
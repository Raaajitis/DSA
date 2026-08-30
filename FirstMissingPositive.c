#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    /*
     * Put every positive number x into
     * index x - 1, whenever possible.
     */
    for (int i = 0; i < n; i++) {

        while (a[i] >= 1 &&
               a[i] <= n &&
               a[a[i] - 1] != a[i]) {

            int correctIndex = a[i] - 1;

            int temp = a[i];
            a[i] = a[correctIndex];
            a[correctIndex] = temp;
        }
    }

    /*
     * Find the first position where the
     * expected value is missing.
     */
    for (int i = 0; i < n; i++) {

        if (a[i] != i + 1) {

            printf("%d\n", i + 1);
            return 0;
        }
    }

    /*
     * If 1...N are all present, the answer
     * is N + 1.
     */
    printf("%d\n", n + 1);

    return 0;
}
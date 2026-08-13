#include <stdio.h>

#define MAXN 100005

int a[MAXN];

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int bestLength = 1;
    int bestStart = 0;

    /* Odd-length palindromes */
    for (int center = 0; center < n; center++) {

        int left = center;
        int right = center;

        while (left >= 0 &&
               right < n &&
               a[left] == a[right]) {

            int length = right - left + 1;

            if (length > bestLength) {
                bestLength = length;
                bestStart = left;
            }

            left--;
            right++;
        }
    }

    /* Even-length palindromes */
    for (int center = 0; center < n - 1; center++) {

        int left = center;
        int right = center + 1;

        while (left >= 0 &&
               right < n &&
               a[left] == a[right]) {

            int length = right - left + 1;

            if (length > bestLength) {
                bestLength = length;
                bestStart = left;
            }

            left--;
            right++;
        }
    }

    printf("Longest length: %d\n", bestLength);

    printf("Window: ");

    for (int i = bestStart;
         i < bestStart + bestLength;
         i++) {

        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}
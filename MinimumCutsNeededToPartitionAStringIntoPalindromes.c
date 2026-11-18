#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX 100

int minimumPalindromeCuts(char str[]) {

    int n = strlen(str);

    if (n == 0) {
        return 0;
    }

    int palindrome[MAX][MAX] = {0};
    int cuts[MAX];

    /*
     * Build palindrome table.
     * We move i backwards so that
     * palindrome[i+1][j-1] is already known.
     */
    for (int i = n - 1; i >= 0; i--) {

        for (int j = i; j < n; j++) {

            if (str[i] == str[j] &&
                (j - i <= 2 ||
                 palindrome[i + 1][j - 1])) {

                palindrome[i][j] = 1;
            }
        }
    }

    // Calculate minimum cuts
    for (int i = 0; i < n; i++) {

        if (palindrome[0][i]) {

            cuts[i] = 0;
        }

        else {

            cuts[i] = INT_MAX;

            for (int j = 0; j < i; j++) {

                /*
                 * str[j+1 ... i] must be
                 * a palindrome.
                 */
                if (palindrome[j + 1][i] &&
                    cuts[j] + 1 < cuts[i]) {

                    cuts[i] = cuts[j] + 1;
                }
            }
        }
    }

    return cuts[n - 1];
}

int main() {

    char str[] = "abccbc";

    int result =
        minimumPalindromeCuts(str);

    printf("Minimum cuts required: %d\n",
           result);

    return 0;
}
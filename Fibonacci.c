#include <stdio.h>

int main() {
    int n;

    // Reading number of terms
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    int first = 0, second = 1, next;

    // Printing Fibonacci series
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", first);
        } else if (i == 2) {
            printf("%d ", second);
        } else {
            next = first + second;
            printf("%d ", next);
            first = second;
            second = next;
        }
    }

    return 0;
}

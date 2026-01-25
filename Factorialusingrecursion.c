#include <stdio.h>

// Recursive function to find factorial
int factorial(int n) {
    if (n == 0) {
        return 1; // Base case
    }
    return n * factorial(n - 1);
}

int main() {
    int n;

    // Reading number
    printf("Enter a number to find its factorial: ");
    scanf("%d", &n);

    // Printing factorial
    printf("The Factorial of %d is: %d", n, factorial(n));

    return 0;
}

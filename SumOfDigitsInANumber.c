#include <stdio.h>

int main() {
    int n, sum = 0;

    // Reading number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculating sum of digits
    while (n != 0) {
        sum = sum + (n % 10); // Gets last digit
        n = n / 10;           // Remove last digit
    }

    // Prints result
    printf("Sum of digits in the number is: %d", sum);

    return 0;
}

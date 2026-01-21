#include <stdio.h>

int main() {
    int n;
    int isPrime = 1; // Assuming number is prime

    // Reading number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Numbers less than or equal to 1 are not prime, so we declare a condition
    if (n <= 1) {
        printf("Not Prime");
        return 0;
    }

    // Checking divisibility
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }

    // Printing result
    if (isPrime) {
        printf("The given number is Prime");
    } else {
        printf("The given number is Not Prime");
    }

    return 0;
}

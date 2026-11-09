#include <stdio.h>

int maximumBalancedParts(char str[]) {

    int balance = 0;
    int parts = 0;

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == '0') {

            balance++;

        } else if (str[i] == '1') {

            balance--;

        } else {

            // Invalid character
            return -1;
        }

        if (balance == 0) {
            parts++;
        }
    }

    // Unequal total number of 0s and 1s
    if (balance != 0) {
        return -1;
    }

    return parts;
}

int main() {

    char str[] = "0100110101";

    int result = maximumBalancedParts(str);

    if (result == -1) {

        printf("Balanced partitioning is impossible.\n");

    } else {

        printf("Maximum balanced parts: %d\n", result);
    }

    return 0;
}
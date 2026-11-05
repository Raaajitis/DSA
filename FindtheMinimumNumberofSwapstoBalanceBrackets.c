#include <stdio.h>
#include <string.h>

#define MAX 1000

int minimumSwaps(char str[]) {

    int n = strlen(str);

    int openPositions[MAX];
    int openCount = 0;

    // Store positions of '['
    for (int i = 0; i < n; i++) {

        if (str[i] == '[') {
            openPositions[openCount++] = i;
        }
    }

    int nextOpen = 0;
    int balance = 0;
    int swaps = 0;

    for (int i = 0; i < n; i++) {

        if (str[i] == '[') {

            balance++;
            nextOpen++;
        }

        else {

            balance--;

            // More closing brackets than opening brackets
            if (balance < 0) {

                int position = openPositions[nextOpen];

                // Swap current ']' with next '['
                char temp = str[i];
                str[i] = str[position];
                str[position] = temp;

                swaps++;

                nextOpen++;

                // After swapping, current character is '['
                balance = 1;
            }
        }
    }

    return swaps;
}

int main() {

    char str[] = "]]][[[";

    int result = minimumSwaps(str);

    printf("Minimum swaps required: %d\n", result);

    printf("Balanced string: %s\n", str);

    return 0;
}
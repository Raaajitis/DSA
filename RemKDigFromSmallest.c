#include <stdio.h>
#include <string.h>

#define MAX 1000

void removeKDigits(char num[], int k) {

    char stack[MAX];

    int top = -1;
    int n = strlen(num);

    for (int i = 0; i < n; i++) {

        while (top >= 0 &&
               k > 0 &&
               stack[top] > num[i]) {

            top--;
            k--;
        }

        stack[++top] = num[i];
    }

    // If digits are still left to remove,
    // remove them from the end.
    while (k > 0 && top >= 0) {

        top--;
        k--;
    }

    // Find first non-zero digit
    int start = 0;

    while (start <= top &&
           stack[start] == '0') {

        start++;
    }

    if (start > top) {

        printf("Smallest number: 0\n");
        return;
    }

    printf("Smallest number: ");

    for (int i = start; i <= top; i++) {

        printf("%c", stack[i]);
    }

    printf("\n");
}

int main() {

    char num[] = "1432219";

    int k = 3;

    removeKDigits(num, k);

    return 0;
}
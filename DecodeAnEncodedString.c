#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

void decodeString(char str[]) {

    char stack[MAX];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] != ']') {

            stack[++top] = str[i];

        } else {

            char temp[MAX];
            int tempIndex = 0;

            // Extract characters until '['
            while (top >= 0 && stack[top] != '[') {
                temp[tempIndex++] = stack[top--];
            }

            // Remove '['
            top--;

            // Reverse extracted substring
            char substring[MAX];

            for (int j = 0; j < tempIndex; j++) {
                substring[j] = temp[tempIndex - j - 1];
            }

            substring[tempIndex] = '\0';

            // Extract the number
            int number = 0;
            int multiplier = 1;

            while (top >= 0 && isdigit(stack[top])) {

                number =
                    (stack[top] - '0') * multiplier
                    + number;

                multiplier *= 10;
                top--;
            }

            // Push repeated substring back
            for (int repeat = 0; repeat < number; repeat++) {

                for (int j = 0; substring[j] != '\0'; j++) {
                    stack[++top] = substring[j];
                }
            }
        }
    }

    printf("Decoded string: ");

    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }

    printf("\n");
}

int main() {

    char str[] = "3[a2[c]]";

    decodeString(str);

    return 0;
}